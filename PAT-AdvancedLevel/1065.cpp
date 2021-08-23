// #include <bits/stdc++.h>
// using namespace std;
// //#define LOCAL
// int t;

// long long a, b, c, res;

// int main()
// {
//     // ios::sync_with_stdio(0);
//     // cin.tie(0);
//     // cout.tie(0);
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     scanf("%d", &t);
//     for (int i = 1; i <= t; ++i)
//     {
//         bool flag = true;
//         scanf("%lld%lld%lld", &a, &b, &c);
//         res = a + b;
//         if (a > 0 and b > 0 and res < 0)
//             flag = true;
//         else if (a < 0 and b < 0 and res >= 0)
//             flag = false;
//         else
//         {
//             if (res > c)
//                 flag = true;
//             else
//                 flag = false;
//         }
//         printf("Case #%d: ", i);
//         if (flag)
//             printf("true");
//         else
//             printf("false");
//         if (i != t)
//             printf("\n");
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
int t;
long double a, b, c;
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> a >> b >> c;
        cout << "Case #" << i << ": " << boolalpha << ((a + b) > c) << "\n";
    }
    return 0;
}