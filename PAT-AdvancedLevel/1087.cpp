// #include <bits/stdc++.h>
// using namespace std;
// //#define LOCAL
// const int N = 210;

// struct City
// {
//     string name;
//     int happy;
// };

// struct Edge
// {
//     int v, c;
// };

// int n, k;
// vector<City> cities;
// unordered_map<string, int> um;
// vector<Edge> g[N];
// int dist[N], happy[N], sz[N];
// bool vis[N];
// int pre[N];
// int ansRoutes, ansCost, ansHappy, ansAvghappy;

// void Dijkstra()
// {
//     memset(dist, 0x3f, sizeof dist);
//     dist[0] = 0;
//     for (int i = 1; i <= n; ++i)
//     {
//         int v = -1;
//         for (int j = 0; j < n; ++j)
//         {
//             if (!vis[j] && (v == -1 || dist[j] < dist[v] || (dist[j] == dist[v] && cities[j].happy > cities[v].happy)))
//             {
//                 v = j;
//             }
//         }
//         vis[v] = true;
//         if (v == um["ROM"])
//             break;
//         for (auto &i : g[v])
//         {
//             int nt = i.v, w = i.c;
//             if (vis[nt])
//                 continue;
//             if (dist[nt] > dist[v] + w)
//             {
//                 dist[nt] = dist[v] + w;
//                 happy[nt] = happy[v] + cities[nt].happy;
//                 sz[nt] = sz[v] + 1;
//                 pre[nt] = v;
//             }
//             if (dist[nt] == dist[v] + w)
//             {
//                 if (happy[nt] < happy[v] + cities[nt].happy)
//                 {
//                     happy[nt] = happy[v] + cities[nt].happy;
//                     sz[nt] = sz[v] + 1;
//                     pre[nt] = v;
//                 }
//                 if (happy[nt] == happy[v] + cities[nt].happy)
//                 {
//                     if (happy[nt] * 1.0 / sz[nt] < (happy[v] + cities[nt].happy) * 1.0 / (sz[v] + 1))
//                     {
//                         sz[nt] = sz[v] + 1;
//                         pre[nt] = v;
//                     }
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     // ios::sync_with_stdio(0);
//     // cin.tie(0);
//     // cout.tie(0);
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     memset(pre, -1, sizeof - 1);
//     string st;
//     cin >> n >> k >> st;
//     cities.push_back({st, 0});
//     um[st] = 0;
//     for (int i = 1; i < n; ++i)
//     {
//         string name;
//         int happy;
//         cin >> name >> happy;
//         cities.push_back({name, happy});
//         um[name] = i;
//     }
//     while (k--)
//     {
//         string s, e;
//         int c;
//         cin >> s >> e >> c;
//         g[um[s]].push_back({um[e], c});
//         g[um[e]].push_back({um[s], c});
//     }
//     Dijkstra();
//     vector<int> path;
//     for (int i = um["ROM"]; i != -1; i = pre[i])
//     {
//         path.push_back(i);
//         ansHappy += cities[i].happy;
//         ansRoutes++;
//     }
//     printf("%d %d %d %d\n", ansRoutes, dist[um["ROM"]], ansHappy, ansHappy / (ansRoutes - 1));
//     for (int i = path.size() - 1; i >= 0; --i)
//     {
//         cout << cities[path[i]].name;
//         cout << (i == 0 ? "" : "->");
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 210, inf = 0x3f3f3f3f;

int n, k;

int g[N][N], weight[N], dist[N];
bool vis[N];

vector<int> pre[N], temppath, path;
unordered_map<string, int> um;
unordered_map<int, string> um2;

int maxvalue, cntpath;
double maxavg;

void Dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        int v = -1, minn = inf;
        for (int j = 0; j < n; ++j)
        {
            if (!vis[j] && dist[j] < minn)
            {
                v = j;
                minn = dist[j];
            }
        }
        if (v == -1)
            break;
        vis[v] = true;
        for (int j = 0; j < n; ++j)
        {
            if (!vis[j] && g[v][j] != inf)
            {
                if (dist[j] > dist[v] + g[v][j])
                {
                    dist[j] = dist[v] + g[v][j];
                    pre[j].clear();
                    pre[j].push_back(v);
                }
                else if (dist[j] == dist[v] + g[v][j])
                {
                    pre[j].push_back(v);
                }
            }
        }
    }
}

void Dfs(int v)
{
    if (v == 0)
    {
        int value = 0;
        for (int i = 0; i < temppath.size(); ++i)
        {
            value += weight[temppath[i]];
        }
        double tempavg = 1.0 * value / (temppath.size() - 1);
        if (value > maxvalue)
        {
            maxvalue = value;
            maxavg = tempavg;
            path = temppath;
        }
        else if (value == maxvalue && tempavg > maxavg)
        {
            maxavg = tempavg;
            path = temppath;
        }
        cntpath++;
        return;
    }
    for (int i = 0; i < pre[v].size(); ++i)
    {
        temppath.push_back(pre[v][i]);
        Dfs(pre[v][i]);
        temppath.pop_back();
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
    string s;
    cin >> n >> k >> s;
    um[s] = 0;
    um2[0] = s;
    for (int i = 1; i < n; ++i)
    {
        cin >> s >> weight[i];
        um[s] = i;
        um2[i] = s;
    }
    string sa, sb;
    int temp;
    for (int i = 0; i < k; ++i)
    {
        cin >> sa >> sb >> temp;
        g[um[sa]][um[sb]] = g[um[sb]][um[sa]] = temp;
    }
    Dijkstra();
    int rom = um["ROM"];
    temppath.push_back(rom);
    Dfs(rom);
    printf("%d %d %d %d\n", cntpath, dist[rom], maxvalue, (int)maxavg);
    for (int i = path.size() - 1; i >= 0; --i)
    {
        cout << um2[path[i]] << (i == 0 ? "" : "->");
    }
    return 0;
}