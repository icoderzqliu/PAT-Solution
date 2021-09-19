#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10010;

int n;

int p[N], score[N];

struct School
{
    int cnt;
    int total;
    int minn = 0x3f3f3f3f;

    bool operator<(const School &s) const
    {
        if (total != s.total)
            return total > s.total;
        if (cnt != s.cnt)
            return cnt < s.cnt;
        return minn < s.minn;
    }
} schools[N];

set<int> stu;

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b)
{
    p[find(a)] = find(b);
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    iota(p, p + N, 0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int id, k;
        cin >> id >> k;
        stu.insert(id);
        for (int i = 0; i < k; ++i)
        {
            int t;
            cin >> t;
            stu.insert(t);
            merge(id, t);
        }
        cin >> score[id];
    }
    int ans = 0;
    vector<int> ansNum;
    for (auto &item : stu)
    {
        int temp = find(item);
        if (temp == item)
        {
            ans++;
            ansNum.push_back(item);
        }
        schools[temp].total += score[item];
        schools[temp].cnt++;
        if (item < schools[temp].minn)
        {
            schools[temp].minn = item;
        }
    }
    vector<School> ansSchool;
    for (auto &item : ansNum)
    {
        ansSchool.push_back(schools[item]);
    }
    sort(ansSchool.begin(), ansSchool.end());
    cout << ansSchool.size();
    for (int i = 0; i < ansSchool.size(); ++i)
    {
        printf("\n%04d %d %d", ansSchool[i].minn, ansSchool[i].cnt, ansSchool[i].total);
    }
    return 0;
}