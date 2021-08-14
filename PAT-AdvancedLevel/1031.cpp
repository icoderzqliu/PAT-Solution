#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10;
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
    cin >> s;
    int len = s.size();
    int n1 = (len + 2) / 3;
    int n2 = (len + 2) - 2 * n1;
    for (int i = 0; i < n1 - 1; ++i)
    {
        cout << s[i];
        for (int j = 0; j < n2 - 2; ++j)
            cout << ' ';
        cout << s[len - 1 - i] << endl;
    }
    for (int i = 0; i < n2; ++i)
    {
        cout << s[n1 - 1 + i];
    }
    return 0;
}