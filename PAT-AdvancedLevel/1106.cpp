#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
typedef pair<int, double> PID;

const int N = 100010;
int n;
double p, r;

vector<int> g[N];
bool isRetailer[N];

double lowest = (double)0x3f3f3f3f;
int sum;

void bfs()
{
    queue<PID> q;
    q.push({0, p});

    while (q.size())
    {
        PID t = q.front();
        q.pop();

        if (isRetailer[t.first])
        {
            if (t.second < lowest)
            {
                lowest = t.second;
                sum = 1;
            }
            else if (t.second == lowest)
            {
                sum++;
            }
        }

        for (auto i : g[t.first])
        {
            q.push({i, t.second * r});
        }
    }
}

void dfs(int u, double price)
{
    if (isRetailer[u])
    {
        if (price < lowest)
        {
            lowest = price;
            sum = 1;
        }
        else if (price == lowest)
        {
            sum++;
        }
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
    scanf("%d%lf%lf", &n, &p, &r);
    r = 1 + r / 100;
    for (int i = 0; i < n; ++i)
    {
        int k;
        scanf("%d", &k);
        if (!k)
            isRetailer[i] = true;
        while (k--)
        {
            int x;
            scanf("%d", &x);
            g[i].push_back(x);
        }
    }
    // bfs();
    dfs(0, p);
    printf("%.4lf %d", lowest, sum);
    return 0;
}