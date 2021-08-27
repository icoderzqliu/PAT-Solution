#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
string s;
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> s;
    if (s[0] == '-')
        cout << "-";
    int ep = s.find('E');
    string front = s.substr(1, ep - 1);
    int exp = stoi(s.substr(ep + 1));
    if (exp < 0)
    {
        cout << "0.";
        cout << string(abs(exp) - 1, '0');
        cout << front[0];
        cout << front.substr(2);
    }
    else
    {
        cout << front[0];
        int i, cnt = 0;
        for (i = 2; i < front.size() && cnt < exp; i++, cnt++)
        {
            cout << front[i];
        }
        if (i == front.size())
        {
            cout << string(exp - cnt, '0');
        }
        else
        {
            cout << ".";
            cout << front.substr(i);
        }
    }
    return 0;
}