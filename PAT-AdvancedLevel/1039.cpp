#include <bits/stdc++.h>
using namespace std;
#define LOCAL
const int N = 40010;

int n, k;

unordered_map<string, set<int>> um;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("1039in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    int cid, num;
    string name;
    for (int i = 1; i <= k; ++i)
    {
        cin >> cid >> num;
        for (int j = 1; j <= num; ++j)
        {
            cin >> name;
            um[name].insert(cid);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> name;
        cout << name << ' ' << um[name].size();
        for (auto &j : um[name])
        {
            cout << ' ' << j;
        }
        cout << endl;
    }
    return 0;
}