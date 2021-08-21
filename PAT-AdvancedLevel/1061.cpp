#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
unordered_map<char, string> week = {{'A', "MON"}, {'B', "TUE"}, {'C', "WED"}, {'D', "THU"}, {'E', "FRI"}, {'F', "SAT"}, {'G', "SUN"}};

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s1, s2, s3, s4;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    getline(cin, s4);
    vector<char> common;
    for (int i = 0; i < s1.size() && i < s2.size(); ++i)
    {
        if (s1[i] == s2[i])
        {
            if (common.size() == 0 && s1[i] >= 'A' && s1[i] <= 'G')
            {
                common.push_back(s1[i]);
            }
            else if (common.size() == 1 && (s1[i] >= 'A' && s1[i] <= 'N' || s1[i] >= '0' && s1[i] <= '9'))
            {
                common.push_back(s1[i]);
            }
        }
    }
    int m;
    for (int i = 0; i < s3.size() && i < s4.size(); ++i)
    {
        if (s3[i] == s4[i] && (s3[i] >= 'A' && s3[i] <= 'Z' || s3[i] >= 'a' && s4[i] <= 'z'))
        {
            m = i;
            break;
        }
    }
    cout << week[common[0]] << " ";
    int h;
    if (common[1] >= 'A' && common[1] <= 'Z')
    {
        h = common[1] - 'A' + 10;
    }
    else
        h = common[1] - '0';
    printf("%02d:%02d", h, m);
    return 0;
}