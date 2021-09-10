#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1e8 + 10;

int n;

vector<int> f(100000);

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
    f[0] = 0, f[1] = 1;
    int i = 1;
    while (f[i] < n)
    {
        f[i + 1] = f[i] + f[i - 1];
        i++;
    }
    cout << (abs(f[i] - n) < abs(f[i - 1] - n) ? f[i] : f[i - 1]);
    return 0;
}