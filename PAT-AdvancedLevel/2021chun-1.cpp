#include <bits/stdc++.h>
using namespace std;
//#define LOCAL

int n, maxx;

vector<bool> vis;
vector<int> prime;
int dmax = -1, res;

void Prime()
{
    for (int i = 2; i <= maxx; ++i)
    {
        if (!vis[i])
        {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && prime[j] * i <= maxx; ++j)
        {
            vis[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
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
    cin >> n >> maxx;
    vis.resize(maxx);
    Prime();
    if (n == 1)
    {
        cout << prime.back();
        return 0;
    }
    for (int i = prime.size() - 1; i >= 0; --i)
    {
        int a = prime[i];
        for (int d = (maxx - a) / (n - 1); d >= 1; d--)
        {
            bool flag = true;
            int cnt = n - 1, t = a;
            while (cnt--)
            {
                t += d;
                if (vis[t])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                if (d > dmax)
                {
                    dmax = d, res = a;
                    break;
                }
            }
        }
    }
    if (dmax != -1)
    {
        for (int i = res, cnt = 0; cnt < n; ++cnt, i += dmax)
        {
            cout << (cnt == 0 ? "" : " ") << i;
        }
    }
    else
        cout << prime.back();
    return 0;
}