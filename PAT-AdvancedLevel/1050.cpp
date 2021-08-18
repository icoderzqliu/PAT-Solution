#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
string s1, s2;
unordered_map<char, bool> um;
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    getline(cin, s1);
    getline(cin, s2);
    for (char &c : s2)
    {
        um[c] = true;
    }
    for (char &c : s1)
    {
        if (!um[c])
            cout << c;
    }
    return 0;
}