#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
typedef long long LL;
const int N = 100010;

int n;
LL p;
vector<LL> seq;
int ans;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> p;
    seq.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> seq[i];
    }
    sort(seq.begin(), seq.end());
    for (int i = 0, j = 0; i <= n - 1; i++)
    {
        while (j <= n - 1 && j >= i && seq[j] <= seq[i] * p)
        {
            j++;
        }
        ans = max(ans, j - i);
    }
    cout << ans;
    return 0;
}