#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1010;

int p, g;
int w[N], ans[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> p >> g;
    for (int i = 0; i < p; ++i)
    {
        cin >> w[i];
    }
    queue<int> q;
    for (int i = 0; i < p; ++i)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    while (q.size() > 1)
    {
        int group = q.size() / g + (q.size() % g != 0);
        int lastg = q.size() % g == 0 ? g : q.size() % g;
        for (int i = 0; i < group; ++i)
        {
            int curnum = (i == group - 1) ? lastg : g;
            int maxx = q.front();
            for (int j = 0; j < curnum; ++j)
            {
                ans[q.front()] = group + 1;
                if (w[q.front()] > w[maxx])
                {
                    maxx = q.front();
                }
                q.pop();
            }
            q.push(maxx);
        }
    }
    ans[q.front()] = 1;
    for (int i = 0; i < p; ++i)
    {
        cout << ans[i] << (i == p - 1 ? "" : " ");
    }
    return 0;
}