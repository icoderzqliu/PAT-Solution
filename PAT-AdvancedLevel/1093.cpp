#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
typedef long long LL;
const int N = 1000010, MOD = 1000000007;

string s;
LL p, pa, pat;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> s;
    for (auto &c : s)
    {
        if (c == 'P')
        {
            p++;
            p = p % MOD;
        }
        else if (c == 'A')
        {
            pa += p;
            pa = pa % MOD;
        }
        else
        {
            pat += pa;
            pat = pat % MOD;
        }
    }
    cout << pat;
    return 0;
}