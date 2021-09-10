// #include <bits/stdc++.h>
// using namespace std;
// //#define LOCAL

// string s, p;

// int main()
// {
//     // ios::sync_with_stdio(0);
//     // cin.tie(0);
//     // cout.tie(0);
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     cin >> s >> p;
//     if (p.size() == 1)
//     {
//         cout << p;
//         return 0;
//     }
//     int minlen = 0x3f3f3f3f, mini = 0x3f3f3f3f;
//     int i = s.find(p[0]);
//     for (; i != -1; i = s.find(p[0], i + 1))
//     {
//         int j = 1, posj = i;
//         while (j < p.size())
//         {
//             posj = s.find(p[j], posj);
//             if (posj == -1)
//             {
//                 break;
//             }
//             else
//                 j++;
//         }
//         if (j == p.size())
//         {
//             if (posj - i + 1 < minlen)
//             {
//                 minlen = posj - i + 1;
//                 mini = i;
//             }
//         }
//     }
//     cout << s.substr(mini, minlen);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL

string s, p;
int minlen = 0x3f3f3f3f;
string ans;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> s >> p;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == p[0])
        {
            int j = i + 1, t = 1;
            while (j < s.size())
            {
                if (s[j] == p[t])
                {
                    j++, t++;
                }
                else
                    j++;
                if (t == p.size())
                    break;
            }
            if (t == p.size())
            {
                if (minlen > j - i)
                {
                    minlen = j - i;
                    ans = s.substr(i, j - i);
                }
            }
        }
    }
    cout << ans;
    return 0;
}