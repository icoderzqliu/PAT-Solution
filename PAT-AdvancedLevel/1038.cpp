#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1010;
int n;
vector<string> v;

bool cmp(const string &s1, const string &s2)
{
    return s1 + s2 < s2 + s1;
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
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    string str = "";
    for (auto i : v)
    {
        str += i;
    }
    int i = 0;
    while (str[i] == '0')
    {
        i++;
    }
    if (i == str.size())
        cout << '0';
    else
        cout << str.substr(i);
    // string str = accumulate(v.begin(), v.end(), string());  //将所有数字拼接在一起
    // //找到第一个不为零的字符
    // auto i = find_if(str.begin(), str.end(), [](char c) { return c != '0'; });
    // //输出不带前导零的数字
    // i == str.end() ? (cout << "0") : (cout << str.substr(i - str.begin()));
    return 0;
}