#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 110;

int n;
vector<int> a, b, tmp;

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
    a.resize(n), b.resize(n), tmp.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp[i];
    }
    a = tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    bool isInsert = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sort(a.begin() + i, a.begin() + j);
        }
    }
    return 0;
}