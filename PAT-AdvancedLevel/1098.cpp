#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 110;
int n;

vector<int> a, b;
int p;

void down(int u)
{
    int t = u;
    if (u * 2 + 2 < p && b[t] < b[u * 2 + 2])
        t = u * 2 + 2;
    if (u * 2 + 1 < p && b[t] < b[u * 2 + 1])
        t = u * 2 + 1;
    if (u != t)
    {
        swap(b[t], b[u]);
        down(t);
    }
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
    cin >> n;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int i, j;
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; ++i)
        ;
    for (j = i + 1; j < n && a[j] == b[j]; ++j)
        ;
    if (j == n)
    {
        cout << "Insertion Sort\n";
        sort(a.begin(), a.begin() + i + 2);
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
    }
    // else
    // {
    //     cout << "Heap Sort\n";
    //     make_heap(a.begin(), a.end());
    //     for (int i = 0; i < n; ++i)
    //     {
    //         pop_heap(a.begin(), a.begin() + n - i);
    //         if (a == b)
    //         {
    //             pop_heap(a.begin(), a.begin() + n - i - 1);
    //             break;
    //         }
    //     }
    // }
    else
    {
        cout << "Heap Sort\n";
        for (p = n - 1; b[p] >= b[1]; p--)
            ;
        swap(b[p], b[0]);
        down(0);
        for (int i = 0; i < n; ++i)
        {
            cout << b[i] << (i == n - 1 ? "" : " ");
        }
    }
    return 0;
}