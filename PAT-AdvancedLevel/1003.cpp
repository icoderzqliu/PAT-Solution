#include <bits/stdc++.h>
using namespace std;
#define DEBUG
const int N = 505;
struct Edge
{
    int v, w;
};

int n, m, c1, c2;
int city[N];       // 每个城市救护队的数量
int pathNum[N];    // 到达每个城市的最短路径的个数
int teamNum[N];    // 到达每个城市的救护队数量
int dist[N];       // 到达每个城市的最短距离
int vis[N];        // 标记是否被访问过
vector<Edge> g[N]; // 邻接表存储图结构

void dijkstra()
{
    while (!vis[c2])
    {
        int MIN = INT_MAX, v = -1;
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i] && dist[i] < MIN)
            {
                MIN = dist[i];
                v = i;
            }
        }
        vis[v] = 1;
        for (Edge e : g[v])
        {
            if (!vis[e.v] && dist[e.v] > dist[v] + e.w)
            {
                dist[e.v] = dist[v] + e.w;
                pathNum[e.v] = pathNum[v];
                teamNum[e.v] = teamNum[v] + city[e.v];
            }
            else if (dist[e.v] == dist[v] + e.w)
            {
                pathNum[e.v] += pathNum[v];
                teamNum[e.v] = max(teamNum[e.v], teamNum[v] + city[e.v]);
            }
        }
    }
}

struct Node
{
    int u, dis;
    bool operator<(const Node &n) const
    {
        return dis > n.dis;
    }
};
void dijkstra2()
{
    priority_queue<Node> pq;
    pq.push({c1, 0});
    while (!pq.empty())
    {
        Node t = pq.top();
        pq.pop();
        if (!vis[t.u])
        {
            vis[t.u] = 1;
            if(t.u==c2){
                break;
            }
            for (Edge e : g[t.u])
            {
                if (!vis[e.v] && dist[e.v] > dist[t.u] + e.w)
                {
                    dist[e.v] = dist[t.u] + e.w;
                    pathNum[e.v] = pathNum[t.u];
                    teamNum[e.v] = teamNum[t.u] + city[e.v];
                    pq.push({e.v,dist[e.v]});
                }
                else if (dist[e.v] == dist[t.u] + e.w)
                {
                    pathNum[e.v] += pathNum[t.u];
                    teamNum[e.v] = max(teamNum[e.v], teamNum[t.u] + city[e.v]);
                }
            }
        }
    }
}
int main()
{
#ifdef DEBUG
    freopen("1003in.txt", "r", stdin);
    freopen("1003out.txt", "w", stdout);
#endif
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &city[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    fill(dist, dist + N, INT_MAX);
    dist[c1] = 0;
    pathNum[c1] = 1;
    teamNum[c1] = city[c1];
    dijkstra2();
    printf("%d %d", pathNum[c2], teamNum[c2]);
    return 0;
}
