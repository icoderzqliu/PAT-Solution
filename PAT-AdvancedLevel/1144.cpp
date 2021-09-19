#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 100005;

int n;
vector<int> a;

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
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int p = lower_bound(a.begin(), a.end(), 0) - a.begin();
    if (p >= n)
    {
        cout << 1;
        return 0;
    }
    for (int i = p + 1; i < n; ++i)
    {
        if (a[i] > a[i - 1] + 1)
        {
            cout << a[i - 1] + 1;
            return 0;
        }
    }
    cout << a[n - 1] + 1;
    return 0;
}