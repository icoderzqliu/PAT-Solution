#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 20;
int n;
int roots[N], cofes[N];

void dfs(int cur, int curpond, int curx)
{
    if (cur == n + 1)
    {
        cofes[curx] += curpond;
        return;
    }
    dfs(cur + 1, -curpond * roots[cur], curx);
    dfs(cur + 1, curpond, curx + 1);
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
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> roots[i];
    }
    dfs(1, 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        cout << cofes[i];
        if (i)
            cout << " ";
    }
    return 0;
}