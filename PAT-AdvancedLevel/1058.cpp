#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
int g1, s1, k1;
int g2, s2, k2;
int g, s, k;
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d.%d.%d", &g1, &s1, &k1);
    scanf("%d.%d.%d", &g2, &s2, &k2);
    k1 += k2;
    k = k1 % 29;
    int t = k1 / 29;
    s1 += s2 + t;
    s = s1 % 17;
    t = s1 / 17;
    g = g1 + g2 + t;
    printf("%d.%d.%d", g, s, k);
    return 0;
}