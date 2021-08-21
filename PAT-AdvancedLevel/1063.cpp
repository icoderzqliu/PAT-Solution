#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 60, M = 10010, K = 2010;

int n, m, k;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    set<int> numbers[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        cin >> m;
        while (m--)
        {
            int x;
            cin >> x;
            numbers[i].insert(x);
        }
    }
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        int nc = 0, nt = numbers[a].size();
        for (int i : numbers[b])
        {
            if (numbers[a].find(i) != numbers[a].end())
                nc++;
            else
                nt++;
        }
        // int nc = count_if(numbers[a].begin(), numbers[a].end(), [&numbers, b](int x) { return numbers[b].count(x); });
        // double ans = double(nc) / (numbers[a].size() + numbers[b].size() - nc) * 100;
        printf("%.1lf%\n", double(nc) / nt * 100);
    }
    return 0;
}