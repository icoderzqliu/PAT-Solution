#include <bits/stdc++.h>
using namespace std;
#define LOCAL

string trans(int x)
{
    string ans = "";
    while (x)
    {
        int q = x / 13;
        int r = x % 13;
        if (r >= 10)
            ans += (r - 10 + 'A');
        else
            ans += (r + '0');
        x /= 13;
    }
    reverse(ans.begin(), ans.end());
    if (ans.size() == 1)
        ans = '0' + ans;
    else if (ans.size() == 0)
    {
        ans = "00" + ans;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("1027in.txt", "r", stdin);
    freopen("1027out.txt", "w", stdout);
#endif
    int r, g, b;
    cin >> r >> g >> b;
    cout << "#" << trans(r) << trans(g) << trans(b);
    return 0;
}