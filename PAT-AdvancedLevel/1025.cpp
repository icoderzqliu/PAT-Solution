#include <bits/stdc++.h>
using namespace std;
#define LOCAL
const int N = 110, K = 310;
int n, k;
struct Person
{
    string regnum;
    int score;
    int locnum;
    int locrk;
    int finalrk;
    bool operator<(const Person &p) const
    {
        return score == p.score ? regnum < p.regnum : score > p.score;
    }
};

vector<Person> students[N], all;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("1025in.txt", "r", stdin);
    // freopen("1025out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> k;
        for (int j = 1; j <= k; ++j)
        {
            string s;
            int score;
            cin >> s >> score;
            Person p;
            p.regnum = s;
            p.score = score;
            p.locnum = i;
            students[i].push_back(p);
        }
        sort(students[i].begin(), students[i].end());
        students[i][0].locrk = 1;
        all.push_back(students[i][0]);
        for (int j = 1; j < k; ++j)
        {
            if (students[i][j].score == students[i][j - 1].score)
            {
                students[i][j].locrk = students[i][j - 1].locrk;
            }
            else
                students[i][j].locrk = j + 1;
            all.push_back(students[i][j]);
        }
    }
    sort(all.begin(), all.end());
    all[0].finalrk = 1;
    for (int i = 1; i < all.size(); ++i)
    {
        if (all[i].score == all[i - 1].score)
            all[i].finalrk = all[i - 1].finalrk;
        else
            all[i].finalrk = i + 1;
    }
    cout << all.size() << endl;
    for (auto i : all)
    {
        cout << i.regnum << ' ' << i.finalrk << ' ' << i.locnum << ' ' << i.locrk << endl;
    }
    return 0;
}