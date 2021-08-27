#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10010, K = 10, M = 100010;
int n, k, m;

struct User
{
    int rk, id, total = 0;
    vector<int> score;
    int num = 0;
    bool isshown = false;

    bool operator<(const User &u) const
    {
        if (total != u.total)
            return total > u.total;
        if (num != u.num)
            return num > u.num;
        return id < u.id;
    }

} users[N];

int p[K];

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= n; ++i)
        users[i].score.resize(k + 1, -2);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &p[i]);
    while (m--)
    {
        int userid, proid, score;
        scanf("%d%d%d", &userid, &proid, &score);
        users[userid].score[proid] = max(users[userid].score[proid], score);
        users[userid].id = userid;
        if (score >= 0)
            users[userid].isshown = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (users[i].score[j] >= 0)
                users[i].total += users[i].score[j];
            if (users[i].score[j] == p[j])
                users[i].num++;
        }
    }
    sort(users + 1, users + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        users[i].rk = i;
        if (i > 1 && users[i].total == users[i - 1].total)
        {
            users[i].rk = users[i - 1].rk;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        User u = users[i];
        if (u.isshown)
        {
            printf("%d %05d %d", u.rk, u.id, u.total);
            for (int j = 1; j <= k; ++j)
            {
                if (u.score[j] == -2)
                    printf(" -");
                else if (u.score[j] == -1)
                    printf(" 0");
                else
                    printf(" %d", u.score[j]);
            }
            printf("\n");
        }
    }
    return 0;
}