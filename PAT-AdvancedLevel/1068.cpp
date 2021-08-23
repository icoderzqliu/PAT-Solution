// #include <bits/stdc++.h>
// using namespace std;
// //#define LOCAL
// const int N = 10010, M = 110;

// int n, m;
// int w[N];
// bool f[M];      // f[i][j]表示1~i的金币是否能表示j的价值
// bool cur[N][M]; // cur[i][j]表示w[i]能否成为组成价值j的硬币

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     cin >> n >> m;
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> w[i];
//     }
//     sort(w + 1, w + n + 1, greater<int>());
//     f[0] = true;
//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = m; j >= w[i]; j--)
//         {
//             if (f[j - w[i]])
//                 f[j] = cur[i][j] = true;
//         }
//     }
//     if (!f[m])
//         cout << "No Solution";
//     else
//     {
//         for (int i = n; i >= 1; --i)
//         {
//             if (cur[i][m])
//             {
//                 cout << w[i] << (m == w[i] ? "\n" : " ");
//                 m -= w[i];
//             }
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10010, M = 110;

int n, m;
int w[N];
int f[M];
bool choice[N][M];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i];
    }
    sort(w + 1, w + n + 1, greater<int>());
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= w[i]; --j)
        {
            if (f[j] <= f[j - w[i]] + w[i])
            {
                choice[i][j] = true;
                f[j] = f[j - w[i]] + w[i];
            }
        }
    }
    if (f[m] != m)
        cout << "No Solution";
    else
    {
        for (int i = n; i >= 1; i--)
        {
            if (choice[i][m])
            {
                cout << w[i] << (w[i] == m ? "" : " ");
                m -= w[i];
            }
        }
    }
    return 0;
}