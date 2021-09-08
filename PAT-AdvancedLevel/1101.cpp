#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 100010, inf = 0x3f3f3f3f;

int n;

set<int> cands;

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
    vector<int> a(n), leftmax(n, -inf), rightmin(n, inf);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i)
    {
        leftmax[i] = max(leftmax[i - 1], a[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i)
    {
        rightmin[i] = min(rightmin[i + 1], a[i + 1]);
    }
    for (int i = 0; i < n; ++i)
    {
        if (leftmax[i] < a[i] && a[i] < rightmin[i])
            cands.insert(a[i]);
    }
    cout << cands.size() << "\n";
    for (auto it = cands.begin(); it != cands.end(); ++it)
    {
        cout << *it << (it == prev(cands.end()) ? "" : " ");
    }
    cout << "\n";
    return 0;
}