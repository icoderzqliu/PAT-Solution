#include <bits/stdc++.h>
using namespace std;
#define LOCAL
const int N = 110;

int n, m, s;

vector<int> g[N];
int w[N];
vector<vector<int>> ans;
vector<int> res;
int sum;

void dfs(int u)
{
    if (sum == s)
    {
        if (g[u].size() == 0)
            ans.push_back(res);
        return;
    }
    if (sum > s)
    {
        return;
    }
    for (int i : g[u])
    {
        res.push_back(w[i]);
        sum += w[i];
        dfs(i);
        sum -= w[i];
        res.pop_back();
    }
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    // freopen("1053in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        int p, cnt;
        scanf("%d%d", &p, &cnt);
        while (cnt--)
        {
            int son;
            scanf("%d", &son);
            g[p].push_back(son);
        }
    }
    sum += w[0];
    res.push_back(w[0]);
    dfs(0);
    sort(ans.begin(), ans.end(), greater<vector<int>>());
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            printf("%d", ans[i][j]);
            if (j < ans[i].size() - 1)
                printf(" ");
            else if (i < ans.size() - 1)
                printf("\n");
        }
    }
    return 0;
}