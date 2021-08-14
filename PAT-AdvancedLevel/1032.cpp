#include <bits/stdc++.h>
using namespace std;
#define LOCAL
const int N = 100010;

int ne[N];
char e[N];
bool vis[N];

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("1032in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int address1, address2, n;
    cin >> address1 >> address2 >> n;
    for (int i = 0; i < n; ++i)
    {
        int address, nt;
        char c;
        cin >> address >> c >> nt;
        e[address] = c;
        ne[address] = nt;
    }
    for (int i = address1; i != -1; i = ne[i])
    {
        vis[i] = true;
    }
    for (int i = address2; i != -1; i = ne[i])
    {
        if (vis[i])
        {
            printf("%05d", i);
            return 0;
        }
        else
            vis[i] = true;
    }
    cout << -1;
    return 0;
}