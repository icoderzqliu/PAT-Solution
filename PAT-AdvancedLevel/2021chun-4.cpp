#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
typedef pair<int, int> PII;

const int N = 210;
int n, m;

// vector<PII> g[N];
int g[N][N];
int dist[N];
bool vis[N];
vector<int> path;
int ans;

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[0] = 0;
    heap.push({0, 0});

    while (heap.size())
    {
        PII t = heap.top();
        heap.pop();

        int u = t.second, dis = t.first;

        if (vis[u])
            continue;
        vis[u] = true;
        path.push_back(u);
        for (int i = 0; i <= n; ++i)
        {
            if (dist[i] > dist[u] + g[u][i])
            {
                dist[i] = dist[u] + g[u][i];
                heap.push({dist[i], i});
            }
        }
    }
}

void floyd()
{
    for (int k = 0; k <= n; ++k)
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void dfs(int u)
{
    path.push_back(u);
    vis[u] = true;
    int min = 0x3f3f3f3f, v = -1;
    for (int i = 0; i <= n; ++i)
    {
        if (!vis[i])
        {
            if (g[u][i] < min)
            {
                min = g[u][i];
                v = i;
            }
        }
    }
    if (v != -1)
    {
        ans += min;
        dfs(v);
    }
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
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while (m--)
    {
        int s1, s2, d;
        cin >> s1 >> s2 >> d;
        // g[s1].push_back({s2, d});
        // g[s2].push_back({s1, d});
        g[s1][s2] = g[s2][s1] = d;
    }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            if (i == j)
                g[i][j] = 0;
    // dijkstra();
    floyd();
    dfs(0);

    for (int i = 0; i < path.size(); ++i)
    {
        cout << (i == 0 ? "" : " ") << path[i];
    }
    cout << "\n";
    if (path.size() == n + 1)
        cout << ans;
    else
    {
        vector<int> cant;
        for (int i = 1; i <= n; ++i)
        {
            if (g[0][i] == 0x3f3f3f3f)
            {
                cant.push_back(i);
            }
        }
        for (int i = 0; i < cant.size(); ++i)
        {
            cout << (i == 0 ? "" : " ") << cant[i];
        }
    }
    return 0;
}