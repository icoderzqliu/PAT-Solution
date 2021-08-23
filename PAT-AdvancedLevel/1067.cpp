#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 100010;

int n;
unordered_map<int, int> um;
int ans, pos = -1;

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
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x == 0)
            pos = i;
        else if (x != i)
        {
            um[x] = i;
        }
    }
    while (um.size())
    {
        if (pos != 0)
        {
            int t = pos;
            swap(pos, um[pos]);
            um.erase(t);
        }
        else
        {
            swap(pos, um.begin()->second);
        }
        ans++;
    }
    cout << ans;
    return 0;
}