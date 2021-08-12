#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
typedef long long LL;
string n;
int k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    vector<int> v1;
    for (char c : n)
    {
        v1.push_back(c - '0');
    }
    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        vector<int> v2 = v1;
        reverse(v1.begin(), v1.end());
        if (v2 == v1)
        {
            break;
        }
        ans++;
        vector<int> add;
        int t = 0;
        for (int i = v1.size() - 1; i >= 0; --i)
        {
            t = v1[i] + v2[i] + t;
            add.push_back(t % 10);
            t /= 10;
        }
        if (t)
            add.push_back(t);
        v1 = add;
    }
    for (int i = v1.size() - 1; i >= 0; --i)
    {
        cout << v1[i];
    }
    cout << endl
         << ans;
    return 0;
}