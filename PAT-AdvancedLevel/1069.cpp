#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1010;

string s;
int c = -1;

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
    while (c != 6174 && c != 0)
    {
        int a = 0, b = 0;
        vector<int> v;
        for (char &c : s)
        {
            v.push_back(c - '0');
        }
        while (v.size() != 4)
        {
            v.push_back(0);
        }
        sort(v.begin(), v.end(), greater<int>());
        for (int &i : v)
        {
            a = a * 10 + i;
        }
        sort(v.begin(), v.end());
        for (int &i : v)
        {
            b = b * 10 + i;
        }
        c = a - b;
        printf("%04d - %04d = %04d\n", a, b, c);
        s = "";
        int temp = c;
        while (temp)
        {
            s += (temp % 10) + '0';
            temp /= 10;
        }
    }
    return 0;
}