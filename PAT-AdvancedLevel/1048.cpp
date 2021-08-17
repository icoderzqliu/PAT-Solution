#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 100010, M = 110;
int n, m;
int a[N];
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
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    for (int i = 0, j = n - 1; i < n; ++i)
    {
        while (j > i && a[i] + a[j] > m)
        {
            j--;
        }
        if (j > i && a[i] + a[j] == m)
        {
            cout << a[i] << ' ' << a[j];
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}