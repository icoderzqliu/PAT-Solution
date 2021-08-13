// #include <bits/stdc++.h>
// using namespace std;
// #define LOCAL
// const int N = 200010;

// long long a[N], b[N], c[N];

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #ifdef LOCAL
//     freopen("1029in.txt", "r", stdin);
//     // freopen("out.txt", "w", stdout);
// #endif
//     int n = 0;
//     int cnt1, cnt2;
//     cin >> cnt1;
//     n += cnt1;
//     for (int i = 0; i < cnt1; ++i)
//     {
//         cin >> a[i];
//     }
//     cin >> cnt2;
//     n += cnt2;
//     for (int i = 0; i < cnt2; ++i)
//     {
//         cin >> b[i];
//     }
//     int i = 0, j = 0, k = 0;
//     while (i < cnt1 && j < cnt2)
//     {
//         if (a[i] < b[j])
//             c[k++] = a[i++];
//         else
//             c[k++] = b[j++];
//         if (k > n / 2)
//             break;
//     }
//     while (i < cnt1)
//     {
//         c[k++] = a[i++];
//         if (k > n / 2)
//             break;
//     }
//     while (j < cnt2)
//     {
//         c[k++] = b[j++];
//         if (k > n / 2)
//             break;
//     }
//     if (n % 2 == 0)
//         cout << c[n / 2 - 1];
//     else
//         cout << c[n / 2];
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
typedef long long LL;
vector<LL> nums;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for (int i = 0; i < 2; ++i)
    {
        int cnt;
        cin >> cnt;
        while (cnt--)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }
    }
    sort(nums.begin(), nums.end());
    if (nums.size() % 2 == 0)
    {
        cout << nums[nums.size() / 2 - 1];
    }
    else
        cout << nums[nums.size() / 2];
    return 0;
}