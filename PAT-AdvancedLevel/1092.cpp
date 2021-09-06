#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
string s, t;
unordered_map<char, int> um;
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> s >> t;
    for (auto &c : s)
    {
        um[c]++;
    }
    int miss = 0, all = s.size();
    for (auto &c : t)
    {
        if (um[c])
        {
            um[c]--;
            all--;
        }
        else
            miss++;
    }
    if (miss)
        cout << "No " << miss;
    else
        cout << "Yes " << all;
    return 0;
}