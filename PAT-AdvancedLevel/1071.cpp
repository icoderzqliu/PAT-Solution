#include <bits/stdc++.h>
using namespace std;
//#define LOCAL

bool cmp(const pair<string, int> &p1, const pair<string, int> &p2)
{
    if (p1.second != p2.second)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s, t = "";
    map<string, int> mp;
    getline(cin, s);
    for (auto &c : s)
    {
        if (isalnum(c))
        {
            c = tolower(c);
            t += c;
        }
        else
        {
            if (t.length())
                mp[t]++;
            t = "";
        }
    }
    if (t.length())
        mp[t]++;
    vector<pair<string, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);
    cout << v.front().first << " " << v.front().second;
    return 0;
}