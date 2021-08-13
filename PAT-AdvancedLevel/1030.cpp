#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 500;
int n, m, s, d;

struct Node
{
    int v, dis, cos;
    bool operator<(const Node &s) const
    {
        return dis == s.dis ? cos > s.cos : dis > s.dis;
    }
};

vector<Node> g[N];
int dist[N], cost[N];
int path[N];
bool vis[N];

void dijkstra(int u)
{
    memset(dist, 0x3f, sizeof dist);
    memset(cost, 0x3f, sizeof cost);
    memset(path, -1, sizeof path);
    priority_queue<Node> heap;
    dist[u] = 0;
    cost[u] = 0;
    heap.push(Node{u, 0, 0});
    while (heap.size())
    {
        Node t = heap.top();
        heap.pop();
        int v = t.v;
        if (vis[v])
            continue;
        vis[v] = true;
        for (Node i : g[v])
        {
            if (dist[i.v] > dist[v] + i.dis)
            {
                dist[i.v] = dist[v] + i.dis;
                cost[i.v] = cost[v] + i.cos;
                heap.push({i.v, dist[i.v], cost[i.v]});
                path[i.v] = v;
            }
            else if (dist[i.v] == dist[v] + i.dis)
            {
                if (cost[i.v] > cost[v] + i.cos)
                {
                    cost[i.v] = cost[v] + i.cos;
                    heap.push({i.v, dist[i.v], cost[i.v]});
                    path[i.v] = v;
                }
            }
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
    cin >> n >> m >> s >> d;
    for (int i = 0; i < m; ++i)
    {
        int u, v, dis, cost;
        cin >> u >> v >> dis >> cost;
        g[u].push_back({v, dis, cost});
        g[v].push_back({u, dis, cost});
    }
    dijkstra(s);
    cout << s << ' ';
    vector<int> ans;
    for (int i = d; i != s; i = path[i])
    {
        ans.push_back(i);
    }
    for (int i = ans.size() - 1; i >= 0; --i)
    {
        cout << ans[i] << ' ';
    }
    cout << dist[d] << ' ' << cost[d];
    return 0;
}