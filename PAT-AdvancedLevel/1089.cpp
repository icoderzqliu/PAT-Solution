#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 110;

int n;
int a[N], b[N];

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
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int i, j;
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; ++i)
        ;
    for (j = i + 1; a[j] == b[j] && j < n; ++j)
        ;
    if (j == n)
    {
        cout << "Insertion Sort\n";
        sort(a, a + i + 2);
    }
    else
    {
        cout << "Merge Sort\n";
        int k = 1, flag = 1;
        while (flag)
        {
            flag = 0;
            for (int i = 0; i < n; ++i)
            {
                if (a[i] != b[i])
                    flag = 1;
            }
            k *= 2;
            for (int i = 0; i + k <= n; i += k)
            {
                sort(a + i, a + i + k);
            }
            sort(a + n / k * k, a + n);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    return 0;
}