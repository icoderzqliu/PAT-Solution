#include <bits/stdc++.h>
using namespace std;
//#define LOCAL

vector<char> worn;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s1, s2;
    cin >> s1 >> s2;
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] != s2[j])
        {
            if (find(worn.begin(), worn.end(), toupper(s1[i])) == worn.end())
                worn.push_back(toupper(s1[i]));
            i++;
        }
        else
        {
            i++, j++;
        }
    }
    while (i < s1.size())
    {
        if (find(worn.begin(), worn.end(), toupper(s1[i])) == worn.end())
            worn.push_back(toupper(s1[i]));
        i++;
    }

    for (auto &i : worn)
    {
        cout << i;
    }
    return 0;
}