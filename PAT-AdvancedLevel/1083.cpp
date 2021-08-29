#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
int n;
struct Stu
{
    string name, id;
    int grade;

    bool operator<(const Stu &s) const
    {
        return grade > s.grade;
    }
};
vector<Stu> v;
int g1, g2;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].name >> v[i].id >> v[i].grade;
    }
    sort(v.begin(), v.end());
    cin >> g1 >> g2;
    int cnt = 0;
    for (auto &i : v)
    {
        if (i.grade >= g1 && i.grade <= g2)
        {
            cout << i.name << " " << i.id << endl;
            cnt++;
        }
    }
    if (!cnt)
        cout << "NONE";
    return 0;
}