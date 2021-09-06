#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
//#define LOCAL
const int N = 110;

int n, m;
vector<int> tree[N];
unordered_map<int, int> um;
int maxl, maxn;

void bfs()
{
    queue<PII> q;
    q.push({1, 1});
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        um[t.second]++;
        if (um[t.second] > maxn)
        {
            maxn = um[t.second];
            maxl = t.second;
        }

        for (auto &i : tree[t.first])
        {
            q.push({i, t.second + 1});
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
    cin >> n >> m;
    while (m--)
    {
        int p, k;
        cin >> p >> k;
        while (k--)
        {
            int son;
            cin >> son;
            tree[p].push_back(son);
        }
    }
    bfs();
    cout << maxn << " " << maxl;
    return 0;
}