#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define LOCAL

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll len = 1, first = n;
    for (ll i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            ll temp = n, curlen = 0;
            for (ll j = i; temp % j == 0; ++j)
            {
                temp /= j;
                ++curlen;
            }
            if (curlen > len || curlen == len && i < first)
            {
                len = curlen;
                first = i;
            }
        }
    }
    cout << len << "\n";
    for (ll i = 0; i < len; ++i)
    {
        cout << first + i << (i == len - 1 ? "" : "*");
    }
    return 0;
}