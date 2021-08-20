#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 110;
int n;
string a, b;

pair<string, int> f(const string &s, int x)
{
    string ans;
    int i = find_if(s.begin(), s.end(), [](char c) { return isdigit(c) and c != '0'; }) - s.begin();
    if (i == s.size())
        return {string(x, '0'), 0};
    for (int j = i; j < s.size(); ++j)
    {
        if (ans.size() < x and isdigit(s[j]))
            ans.push_back(s[j]);
    }
    ans += string(x - ans.size(), '0');
    int dotp = s.find('.');
    if (dotp == -1)
        dotp = s.size();
    return { ans, dotp > i ? dotp - i : dotp - i + 1 };
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> a >> b;
    auto ansa = f(a, n);
    auto ansb = f(b, n);
    if (ansa == ansb)
    {
        cout << "YES 0." << ansa.first << "*10^" << ansa.second;
    }
    else
    {
        cout << "NO 0." << ansa.first << "*10^" << ansa.second << " 0." << ansb.first << "*10^" << ansb.second;
    }
    return 0;
}
