#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 110;

vector<string> a = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
vector<string> b = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int n;

string trans(string s)
{
    string t = "";
    if (isdigit(s[0]))
    {
        int num = stoi(s);
        if (num / 13)
            t += b[num / 13];
        if (num / 13 && num % 13 != 0)
            t += " ";
        if (num % 13 != 0 || num / 13 == 0 && num % 13 == 0)
            t += a[num % 13];
    }
    else
    {
        stringstream ss(s);
        string temp;
        vector<string> vs;
        int ans = 0;
        while (ss >> temp)
        {
            vs.push_back(temp);
        }
        int p1, p2;
        if (vs.size() == 2)
        {
            p1 = find(b.begin(), b.end(), vs[0]) - b.begin();
            p2 = find(a.begin(), a.end(), vs[1]) - a.begin();
            ans = p1 * 13 + p2;
        }
        else
        {
            p1 = find(b.begin(), b.end(), vs[0]) - b.begin();
            p2 = find(a.begin(), a.end(), vs[0]) - a.begin();
            if (p1 > 0 && p1 < 13)
                ans = p1 * 13;
            if (p2 > 0 && p2 < 13)
                ans = p2;
        }
        t = to_string(ans);
    }
    return t;
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
    cin >> n;
    getchar();
    string s;
    while (n--)
    {
        getline(cin, s);
        cout << trans(s) << "\n";
    }
    return 0;
}