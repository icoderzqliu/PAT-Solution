#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
typedef pair<int, double> PID;
const int N = 100010;

int n;
double p, r;
vector<int> g[N];
double retail[N];
bool vis[N];
double sum;

void bfs()
{
    queue<PID> q;
    q.push({0, 1});
    vis[0] = true;
    while (q.size())
    {
        PID t = q.front();
        q.pop();
        if (g[t.first].size() == 0)
        {
            sum += retail[t.first] * t.second * p;
        }
        for (auto &i : g[t.first])
        {
            if (!vis[i])
            {
                vis[i] = true;
                q.push({i, t.second * r});
            }
        }
    }
}

void dfs(int u, double price)
{
    if (g[u].size() == 0)
    {
        sum += retail[u] * price;
        return;
    }
    for (auto i : g[u])
    {
        dfs(i, price * r);
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
    cin >> n >> p >> r;
    r = 1 + r / 100;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        if (k == 0)
        {
            cin >> retail[i];
        }
        while (k--)
        {
            int b;
            cin >> b;
            g[i].push_back(b);
        }
    }
    // bfs();
    dfs(0, p);
    printf("%.1f", sum);
    return 0;
}