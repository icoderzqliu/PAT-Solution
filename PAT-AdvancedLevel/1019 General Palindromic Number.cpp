#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1e9 + 10;

vector<int> trans(int n, int b)
{
    vector<int> ans;
    while (n)
    {
        int q = n / b;
        int r = n - q * b;
        ans.push_back(r);
        n = q;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("1019in.txt", "r", stdin);
    freopen("1019out.txt", "w", stdout);
#endif
    int n, b;
    cin >> n >> b;
    vector<int> ans = trans(n, b);
    vector<int> tmp = ans;
    reverse(ans.begin(), ans.end());
    if (tmp == ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        if (i == ans.size() - 1)
            cout << ans[i];
        else
            cout << ans[i] << ' ';
    }
    return 0;
}