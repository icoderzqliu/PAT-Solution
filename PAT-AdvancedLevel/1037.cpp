#include <bits/stdc++.h>
using namespace std;
#define LOCAL
typedef long long LL;
const int N = 100010;

int nc, np;
vector<int> coupons[2], products[2];
bool cuse[N], puse[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("1037in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    cin >> nc;
    int x;
    for (int i = 0; i < nc; ++i)
    {

        cin >> x;
        if (x < 0)
            coupons[0].push_back(x);
        else
            coupons[1].push_back(x);
    }
    sort(coupons[0].begin(), coupons[0].end());
    sort(coupons[1].begin(), coupons[1].end(), greater<int>());
    cin >> np;
    for (int i = 0; i < np; ++i)
    {
        cin >> x;
        if (x < 0)
            products[0].push_back(x);
        else
            products[1].push_back(x);
    }
    sort(products[0].begin(), products[0].end());
    sort(products[1].begin(), products[1].end(), greater<int>());
    LL ans = 0;
    for (int i = 0; i < coupons[0].size(); ++i)
    {
        if (i < products[0].size())
        {
            ans += coupons[0][i] * products[0][i];
        }
    }
    for (int i = 0; i < coupons[1].size(); ++i)
    {
        if (i < products[1].size())
        {
            ans += coupons[1][i] * products[1][i];
        }
    }
    cout << ans;
    return 0;
}