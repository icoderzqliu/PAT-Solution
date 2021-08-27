#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
typedef pair<int, int> PII;
const int N = 1010;

int n, l, k;
vector<int> g[N];
bool vis[N];

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int b;
            cin >> b;
            g[b].push_back(i);
        }
    }
    cin >> k;
    while (k--)
    {
        int query;
        cin >> query;
        int ans = 0;
        queue<PII> q;
        memset(vis, false, sizeof vis);
        q.push({query, 0});
        vis[query] = true;
        while (q.size())
        {
            PII t = q.front();
            q.pop();
            if (t.second > l)
                break;
            ans++;
            for (auto &i : g[t.first])
            {
                if (!vis[i])
                {
                    vis[i] = true;
                    q.push({i, t.second + 1});
                }
            }
        }
        cout << ans - 1 << "\n";
    }

    return 0;
}