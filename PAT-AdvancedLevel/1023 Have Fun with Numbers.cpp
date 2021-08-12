#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 22;
string src;
vector<int> v1, v2;
map<int, int> m1, m2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> src;
    for (char c : src)
    {
        v1.push_back(c - '0');
        m1[c - '0']++;
    }
    int t = 0;
    for (int i = v1.size() - 1; i >= 0; --i)
    {
        int c = v1[i] * 2 + t;
        v2.push_back(c % 10);
        m2[c % 10]++;
        t = c / 10;
    }
    if (t)
    {
        v2.push_back(t);
        m2[t]++;
    }
    bool flag = true;
    if (m1.size() != m2.size())
        flag = false;
    else
    {
        for (auto i : m1)
        {
            if (i.second != m2[i.first])
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (int i = v2.size() - 1; i >= 0; --i)
    {
        cout << v2[i];
    }
    return 0;
}