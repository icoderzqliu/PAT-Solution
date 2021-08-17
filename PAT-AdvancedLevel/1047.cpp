#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 40010, K = 2510;
int n, k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    vector<int> courses[k + 1];
    vector<string> names(n + 1);
    string name;
    int num, cid;
    for (int i = 1; i <= n; ++i)
    {
        cin >> name >> num;
        names[i] = name;
        while (num--)
        {
            cin >> cid;
            courses[cid].push_back(i);
        }
    }
    for (int i = 1; i <= k; ++i)
    {
        cout << i << ' ' << courses[i].size() << "\n";
        sort(courses[i].begin(), courses[i].end(), [&names](int a, int b) { return names[a] < names[b]; });
        for (int &j : courses[i])
        {
            cout << names[j] << "\n";
        }
    }

    return 0;
}