#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10010;
int n;

int p[N], num[N];

unordered_map<int, int> hobby;

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int Union(int a, int b)
{
    p[find(a)] = find(b);
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    iota(p, p + n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int k;
        scanf("%d:", &k);
        for (int j = 0; j < k; ++j)
        {
            int x;
            scanf("%d", &x);
            if (hobby.count(x) == 0)
            {
                hobby[x] = i;
            }
            Union(hobby[x], i);
        }
    }
    int roots = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] == i)
            roots++;
        num[find(i)]++;
    }
    sort(num + 1, num + 1 + n, greater<int>());
    cout << roots << "\n";
    for (int i = 1; i <= roots; ++i)
    {
        cout << num[i] << (i == roots ? "" : " ");
    }
    return 0;
}