#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1010;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    getline(cin, s);
    int ans = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = 0; i - j >= 0 and i + j < s.size() and s[i - j] == s[i + j]; ++j)
        {
            ans = max(ans, 2 * j + 1);
        }
        for (int j = 0; i - j >= 0 and i + 1 + j < s.size() and s[i - j] == s[i + 1 + j]; ++j)
        {
            ans = max(ans, 2 * j + 2);
        }
    }
    cout << ans;
    return 0;
}