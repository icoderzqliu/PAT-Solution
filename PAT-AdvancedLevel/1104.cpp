#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 100010;

int n;
long double ans;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        long double a;
        scanf("%Lf", &a);
        ans += a * (i + 1) * (n - i);
    }
    printf("%.2Lf", ans);
    return 0;
}