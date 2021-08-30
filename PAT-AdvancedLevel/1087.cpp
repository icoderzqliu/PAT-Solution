#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 210;

struct City
{
    string name;
    int happy;
};

struct Edge
{
    int v, c;
};

int n, k;
vector<City> cities;
unordered_map<string, int> um;
vector<Edge> g[N];
int dist[N], happy[N], sz[N];
bool vis[N];
int pre[N];
int ansRoutes, ansCost, ansHappy, ansAvghappy;

void Dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int v = -1;
        for (int j = 0; j < n; ++j)
        {
            if (!vis[j] && (v == -1 || dist[j] < dist[v] || (dist[j] == dist[v] && cities[j].happy > cities[v].happy)))
            {
                v = j;
            }
        }
        vis[v] = true;
        if (v == um["ROM"])
            break;
        for (auto &i : g[v])
        {
            int nt = i.v, w = i.c;
            if (vis[nt])
                continue;
            if (dist[nt] > dist[v] + w)
            {
                dist[nt] = dist[v] + w;
                happy[nt] = happy[v] + cities[nt].happy;
                sz[nt]++;
                pre[nt] = v;
            }
            if (dist[nt] == dist[v] + w)
            {
                if (happy[nt] < happy[v] + cities[nt].happy)
                {
                    happy[nt] = happy[v] + cities[nt].happy;
                    sz[nt]++;
                    pre[nt] = v;
                }
                if (happy[nt] == happy[v] + cities[nt].happy)
                {
                    if (happy[nt] * 1.0 / sz[nt] < (happy[v] + cities[nt].happy) * 1.0 / (sz[v] + 1))
                    {
                        sz[nt]++;
                        pre[nt] = v;
                    }
                }
            }
        }
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
    memset(pre, -1, sizeof - 1);
    string st;
    cin >> n >> k >> st;
    cities.push_back({st, 0});
    um[st] = 0;
    for (int i = 1; i < n; ++i)
    {
        string name;
        int happy;
        cin >> name >> happy;
        cities.push_back({name, happy});
        um[name] = i;
    }
    while (k--)
    {
        string s, e;
        int c;
        cin >> s >> e >> c;
        g[um[s]].push_back({um[e], c});
        g[um[e]].push_back({um[s], c});
    }
    Dijkstra();
    vector<int> path;
    for (int i = um["ROM"]; i != -1; i = pre[i])
    {
        path.push_back(i);
        ansHappy += cities[i].happy;
        ansRoutes++;
    }
    printf("%d %d %d %d\n", ansRoutes, dist[um["ROM"]], ansHappy, ansHappy / (ansRoutes - 1));
    for (int i = path.size() - 1; i >= 0; --i)
    {
        cout << cities[path[i]].name;
        cout << (i == 0 ? "" : "->");
    }
    return 0;
}