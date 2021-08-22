#include <bits/stdc++.h>
using namespace std;
//#define LOCAL

const int N = 1010;
int n;
vector<int> order, level;
int idx;

void inOrder(int root)
{
    if (root >= n)
        return;
    inOrder(2 * root + 1);
    level[root] = order[idx++];
    inOrder(2 * root + 2);
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
    order.resize(n);
    level.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> order[i];
    }
    sort(order.begin(), order.end());
    inOrder(0);
    for (int i = 0; i < n; ++i)
    {
        cout << (i == 0 ? "" : " ");
        cout << level[i];
    }
    return 0;
}