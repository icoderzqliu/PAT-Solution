// #include <bits/stdc++.h>
// using namespace std;
// //#define LOCAL

// int n;
// int cnt;

// int find(int x)
// {
//     int ans = 0;
//     while (x)
//     {
//         if (x % 10 == 1)
//             ans++;
//         x /= 10;
//     }
//     return ans;
// }

// int main()
// {
//     // ios::sync_with_stdio(0);
//     // cin.tie(0);
//     // cout.tie(0);
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     scanf("%d", &n);
//     for (int i = 1; i <= n; ++i)
//     {
//         cnt += find(i);
//     }
//     printf("%d", cnt);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
int n;
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
    int ans = 0;
    int left = n / 10, right = 0, current = n % 10;
    for (int i = 1; right != n; i *= 10)
    {
        ans += left * i + (current == 0 ? 0 : (current == 1 ? (right + 1) : i));
        right += current * i;
        current = left % 10;
        left /= 10;
    }
    cout << ans;
    return 0;
}