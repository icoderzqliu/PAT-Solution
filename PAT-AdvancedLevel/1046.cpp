#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 100010;
int n;
int dist[N];
int s[N];
int sum;
int m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> dist[i];
        sum += dist[i];
        s[i] = s[i - 1] + dist[i];
    }
    cin >> m;
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        int t = s[b - 1] - s[a - 1];
        cout << min(t, sum - t) << endl;
    }
    return 0;
}