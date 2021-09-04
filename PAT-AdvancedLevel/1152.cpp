#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define LOCAL
const int L = 1010;

int l, k;
string origin;

bool isPrime(LL x)
{

    for (LL i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
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
    cin >> l >> k;
    cin >> origin;
    for (int i = 0; i + k - 1 < l; i++)
    {
        LL x = stoll(origin.substr(i, k));
        if (x > 1 && isPrime(x))
        {
            string s = to_string(x);
            s = string(k - s.size(), '0') + s;
            cout << s;
            return 0;
        }
    }
    cout << 404;
    return 0;
}