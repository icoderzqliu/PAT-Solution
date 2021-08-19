#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 610, M = 810;

int m, n;
int g[N][M];
map<int, int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int x;
            cin >> x;
            mp[x]++;
            if (mp[x] > m * n / 2)
            {
                cout << x;
                return 0;
            }
        }
    }
    return 0;
}