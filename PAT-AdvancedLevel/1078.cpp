#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10010, null = 0x3f3f3f3f;

int m, n;
int h[N];

int insert(int x)
{
    int k = (x % m + m) % m;
    for (int i = 0; i < m; i++)
    {
        int t = (k + i * i) % m;
        if (h[t] == null)
        {
            h[t] = x;
            return t;
        }
    }
    return -1;
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
    memset(h, 0x3f, sizeof h);
    cin >> m >> n;
    int k;
    for (k = m;; k++)
    {
        bool flag = true;
        for (int j = 2; j * j <= k; ++j)
        {
            if (k % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            break;
    }
    m = k;
    if (m == 1)
        m = 2;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        int ans = insert(x);
        if (ans == -1)
            cout << "-";
        else
            cout << ans;
        cout << (i == n - 1 ? "" : " ");
    }
    return 0;
}