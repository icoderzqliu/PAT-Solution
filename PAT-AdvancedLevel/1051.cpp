#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
int m, n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> m >> n >> k;
    vector<int> seq(n);
    while (k--)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> seq[i];
        }
        int cur = 0;
        stack<int> st;
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            st.push(i);
            if (st.size() > m)
            {
                flag = false;
                break;
            }
            while (st.size() > 0 && st.top() == seq[cur])
            {
                st.pop();
                cur++;
            }
        }
        if (flag && st.size() == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}