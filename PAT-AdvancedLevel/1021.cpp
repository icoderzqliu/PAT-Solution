// #include <bits/stdc++.h>
// using namespace std;
// //#define LOCAL
// typedef pair<int, int> PII;
// const int N = 10010;

// int n;
// vector<int> g[N];
// int p[N];
// bool vis[N];

// int find(int x)
// {
//     if (p[x] != x)
//         p[x] = find(p[x]);
//     return p[x];
// }

// int bfs(int u)
// {
//     int res = 0;
//     queue<PII> q;
//     q.push({u, 0});
//     vis[u] = true;
//     while (q.size())
//     {
//         PII t = q.front();
//         q.pop();
//         int v = t.first, dis = t.second;
//         res = max(res, dis);
//         for (int i : g[v])
//         {
//             if (!vis[i])
//             {
//                 q.push({i, dis + 1});
//                 vis[i] = true;
//             }
//         }
//     }
//     return res;
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     cin >> n;
//     iota(p, p + n + 1, 0);
//     for (int i = 1; i <= n - 1; ++i)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//         int ua = find(a);
//         int ub = find(b);
//         if (ua != ub)
//             p[ua] = ub;
//     }
//     int cnt = 0;
//     for (int i = 1; i <= n; ++i)
//     {
//         if (p[i] == i)
//             cnt++;
//     }
//     if (cnt > 1)
//     {
//         cout << "Error: " << cnt << " components";
//     }
//     else
//     {
//         vector<PII> roots;
//         for (int i = 1; i <= n; ++i)
//         {
//             memset(vis, false, sizeof(vis));
//             int res = bfs(i);
//             roots.push_back({res, i});
//         }
//         sort(roots.begin(), roots.end(), greater<PII>());
//         vector<int> ans;
//         ans.push_back(roots[0].second);
//         for (int i = 1; i < n; ++i)
//         {
//             if (roots[i].first == roots[i - 1].first)
//             {
//                 ans.push_back(roots[i].second);
//             }
//             else
//                 break;
//         }
//         sort(ans.begin(), ans.end());
//         for (int i = 0; i < ans.size(); ++i)
//         {
//             if (i != ans.size() - 1)
//                 cout << ans[i] << endl;
//             else
//                 cout << ans[i];
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10010;

int n;
vector<int> g[N];
bool vis[N];
set<int> ans;
vector<int> tmp;
int ansv, anslay;

void dfs(int u, int level)
{
    vis[u] = true;
    if (level > anslay)
    {
        tmp.clear();
        tmp.push_back(u);
        anslay = level;
    }
    else if (level == anslay)
    {
        tmp.push_back(u);
    }
    for (int v : g[u])
    {
        if (!vis[v])
        {
            dfs(v, level + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            dfs(i, 1);
            if (i == 1)
            {
                ansv = tmp[0];
                for (int i : tmp)
                {
                    ans.insert(i);
                }
            }
            cnt++;
        }
    }
    if (cnt > 1)
    {
        cout << "Error: " << cnt << " components";
    }
    else
    {
        memset(vis, false, sizeof vis);
        anslay = 0;
        tmp.clear();
        dfs(ansv, 1);
        for (int i : tmp)
        {
            ans.insert(i);
        }
        for (auto it = ans.begin(); it != ans.end(); ++it)
        {
            if (it != prev(ans.end()))
                cout << *it << endl;
            else
                cout << *it;
        }
    }
    return 0;
}