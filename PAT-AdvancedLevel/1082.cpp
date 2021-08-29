#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
unordered_map<char, string> num = {{'0', "ling"}, {'1', "yi"}, {'2', "er"}, {'3', "san"}, {'4', "si"}, {'5', "wu"}, {'6', "liu"}, {'7', "qi"}, {'8', "ba"}, {'9', "jiu"}};
unordered_map<int, string> danwei = {{8, "Yi"}, {4, "Wan"}, {3, "Qian"}, {2, "Bai"}, {1, "Shi"}};
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int k = (s[0] == '-' ? 1 : 0);
    if (s[0] == '-')
    {
        cout << "Fu ";
        s.erase(0, 1);
    }
    if (stoi(s) == 0)
    {
        cout << "ling";
        return 0;
    }
    reverse(s.begin(), s.end());
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] != '0')
        {
            if (s[i + 1] == '0')
                cout << " ling";
            cout << (i == s.size() - 1 ? "" : " ") << num[s[i]];
        }
        int q = i / 4, r = i % 4;
        if (r == 0)
        {
            if (q == 2)
                cout << " Yi";
            if (q == 1)
                cout << " Wan";
        }
        else if (s[i] != '0')
            cout << " " << danwei[r];
    }
    return 0;
}