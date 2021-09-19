// #include <bits/stdc++.h>
// using namespace std;
// //#define LOCAL
// const int N = 100010;

// int n, d;
// int products[N], coupons[N];
// int s[N];

// int main()
// {
//     // ios::sync_with_stdio(0);
//     // cin.tie(0);
//     // cout.tie(0);
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     cin >> n >> d;
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> products[i];
//     }
//     sort(products, products + n);
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> coupons[i];
//     }
//     sort(coupons, coupons + n, greater<int>());
//     for (int i = 1; i <= n; ++i)
//     {
//         s[i] = s[i - 1] + coupons[i];
//     }
//     int ans = 0;
//     for (int i = 1; i <= n; ++i)
//     {
//         int j;
//         for (j = 1; j <= n; ++j)
//         {
//             if (products[i] * j - coupons[j] > d)
//             {
//                 break;
//             }
//         }
//         ans += j - 1;
//     }
//     return 0;
// }
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 100000;
int A[maxn], B[maxn], record[maxn];
bool cmp(int a, int b)
{
    return a > b;
}
struct node
{
    int product;
    int coupon;
    friend bool operator<(node a, node b)
    {
        return A[a.product] - B[a.coupon] > A[b.product] - B[b.coupon];
    }
};
int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
    }
    sort(A, A + n);
    sort(B, B + n, cmp);
    priority_queue<node> q;
    node tmp;
    for (int i = 0; i < n; i++)
    {
        tmp.product = i;
        tmp.coupon = 0;
        q.push(tmp);
    }
    int total = 0, cnt = 0;
    while (!q.empty())
    {
        tmp = q.top();
        q.pop();
        cnt++;
        total += (A[tmp.product] - B[tmp.coupon]);
        //printf("%d\n",(A[tmp.product]-B[tmp.coupon]));
        if (total > d)
        {
            total -= (A[tmp.product] - B[tmp.coupon]);
            cnt--;
            break;
        }
        if (tmp.coupon < n - 1)
        {
            tmp.coupon++;
            q.push(tmp);
        }
    }
    printf("%d %d\n", cnt, d - total);
    return 0;
}