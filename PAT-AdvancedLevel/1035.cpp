#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
typedef pair<string, string> PSS;
const int N = 1010;

unordered_map<char, char> um = {{'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};

int n;
vector<PSS> ans;

string check(string src)
{
    for (char &c : src)
    {
        if (um.count(c))
            c = um[c];
    }
    return src;
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
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string name, pwd;
        cin >> name >> pwd;
        string trans = check(pwd);
        if (trans != pwd)
            ans.push_back({name, trans});
    }
    if (ans.size())
    {
        cout << ans.size() << endl;
        for (auto &i : ans)
        {
            cout << i.first << ' ' << i.second << endl;
        }
    }
    else if (n == 1)
    {
        cout << "There is 1 account and no account is modified";
    }
    else
    {
        cout << "There are " << n << " accounts and no account is modified";
    }
    return 0;
}