#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 25;

int k;
vector<int> a(55), ans(55), temp(55);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> k;
    for (int i = 1; i <= 54; ++i)
    {
        cin >> a[i];
    }
    iota(ans.begin(), ans.end(), 0);
    while (k--)
    {
        for (int i = 1; i <= 54; ++i)
        {
            temp[a[i]] = ans[i];
        }
        ans = temp;
    }
    string s = "SHCDJ";
    for (int i = 1; i <= 54; ++i)
    {
        cout << (i == 1 ? "" : " ") << s[(ans[i] - 1) / 13] << (ans[i] - 1) % 13 + 1;
    }
    return 0;
}
