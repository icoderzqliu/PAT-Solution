#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 110;

int n;
vector<string> v;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("1077in.txt", "r", stdin);
    freopen("1077out.txt", "w", stdout);
#endif
    cin >> n;
    int minlen = 0x3f3f3f3f;
    getchar();
    // cin.ignore();
    while (n--)
    {
        string s;
        getline(cin, s);
        v.push_back(s);
        if (s.size() < minlen)
            minlen = s.size();
    }
    string common = "";
    for (int i = 0; i < minlen; ++i)
    {
        char temp = v[0][v[0].size() - 1 - i];
        int j;
        for (j = 1; j < v.size(); ++j)
        {
            if (temp != v[j][v[j].size() - 1 - i])
            {
                break;
            }
        }
        if (j == v.size())
        {
            common += temp;
        }
        else
        {
            break;
        }
    }
    if (!common.empty())
    {
        common.erase(0, common.find_first_not_of(" "));
        common.erase(common.find_last_not_of(" ") + 1);
    }
    if (common == "")
    {
        cout << "nai";
    }
    else
    {
        for (int i = common.size() - 1; i >= 0; --i)
        {
            cout << common[i];
        }
    }
    return 0;
}
