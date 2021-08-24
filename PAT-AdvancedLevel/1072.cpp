#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1100, M = 20, K = 10010;
typedef pair<int, int> PII;

struct Edge
{
    int v, c;
};

int n, m, k, d;
vector<Edge> g[N];
int dist[N];
bool vis[N];

int trans(string s)
{
    return s[0] == 'G' ? stoi(s.substr(1)) + n : stoi(s);
}

void Dijkstra(int u)
{
    memset(dist, 0x3f, sizeof dist);
    memset(vis, false, sizeof vis);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[u] = 0;
    heap.push({0, u});

    while (heap.size())
    {
        PII t = heap.top();
        heap.pop();

        int v = t.second;
        if (vis[v])
            continue;
        vis[v] = true;

        for (auto i : g[v])
        {
            int j = i.v, cost = i.c;
            if (dist[j] > dist[v] + cost)
            {
                dist[j] = dist[v] + cost;
                heap.push({dist[j], j});
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
    cin >> n >> m >> k >> d;
    while (k--)
    {
        string p1, p2;
        int dis;
        cin >> p1 >> p2 >> dis;
        int a = trans(p1), b = trans(p2);
        g[a].push_back({b, dis});
        g[b].push_back({a, dis});
    }
    int ans = -1;
    double mindis = 0;
    double avg = 0x3f3f3f3f;
    for (int i = n + 1; i <= n + m; ++i)
    {
        Dijkstra(i);
        int curmindis = 0x3f3f3f3f, curmaxdis = -1;
        double sum = 0;
        for (int j = 1; j <= n; ++j)
        {
            sum += dist[j];
            if (dist[j] < curmindis)
                curmindis = dist[j];
            if (dist[j] > curmaxdis)
                curmaxdis = dist[j];
        }
        double curavg = sum / n;
        if (curmaxdis <= d && (curmindis > mindis || (curmindis == mindis && curavg < avg)))
        {
            ans = i;
            mindis = curmindis;
            avg = curavg;
        }
    }
    if (ans == -1)
        cout << "No Solution";
    else
    {
        printf("G%d\n", ans - n);
        printf("%.1lf %.1lf", mindis, avg);
    }
    return 0;
}