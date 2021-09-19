#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10010;

int s, n, m;

int h[N];

int find(int x)
{
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
    cin >> s >> n >> m;
    bool flag = true;
    int i;
    for (i = s;; ++i)
    {
        for (int j = 2; j * j < i; ++j)
        {
            if (i % j == 0)
                flag = false;
        }
        if (flag == true)
            break;
    }
    s = i;
    for(int i = 0;i<n;++i)
    {
        int x;
        
    }
    return 0;
}