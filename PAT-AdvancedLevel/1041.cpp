#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10010;
int n, k;
unordered_map<int, int> um;
vector<int> v;
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
    int num;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        um[num]++;
        if (um[num] == 1)
            v.push_back(num);
    }
    for (auto &i : v)
    {
        if (um[i] == 1)
        {
            cout << i;
            return 0;
        }
    }
    cout << "None";
    return 0;
}