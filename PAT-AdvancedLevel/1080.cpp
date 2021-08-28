#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 40040, M = 110, K = 10;

struct Stu
{
    int id, ge, gi, rk, total = 0;
    vector<int> prefer;

    bool operator<(const Stu &s) const
    {
        if (total != s.total)
            return total > s.total;
        return ge > s.ge;
    }
} stu[N];

bool cmp(const Stu &s1, const Stu &s2)
{
    return s1.id < s2.id;
}

int n, m, k;
int quota[M];
vector<Stu> admit[M];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        stu[i].prefer.resize(k);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> quota[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> stu[i].ge >> stu[i].gi;
        stu[i].total = stu[i].ge + stu[i].gi;
        stu[i].id = i;
        for (int j = 0; j < k; ++j)
        {
            cin >> stu[i].prefer[j];
        }
    }
    sort(stu, stu + n);
    for (int i = 0; i < n; ++i)
    {
        stu[i].rk = i;
        if (i != 0 && stu[i].total == stu[i - 1].total && stu[i].ge == stu[i - 1].ge)
            stu[i].rk = stu[i - 1].rk;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            int curpre = stu[i].prefer[j];
            if (quota[curpre])
            {
                admit[curpre].push_back(stu[i]);
                quota[curpre]--;
                break;
            }
            else
            {
                if (stu[i].rk == admit[curpre].back().rk)
                {
                    admit[curpre].push_back(stu[i]);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        sort(admit[i].begin(), admit[i].end(), cmp);
        for (int j = 0; j < admit[i].size(); ++j)
        {
            cout << (j == 0 ? "" : " ");
            cout << admit[i][j].id;
        }
        cout << endl;
    }
    return 0;
}