#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 50010;

int n;
vector<int> pre, in;
bool flag = false;

void post(int root, int start, int end)
{
    if (start == end)
    {
        cout << pre[root];
        return;
    }
    int i = find(in.begin(), in.end(), pre[root]) - in.begin();
    if (i > start)
        post(root + 1, start, i - 1);
    else
        post(root + 1 + i - start, i + 1, end);
}

void post1(int root, int start, int end)
{
    if (start > end || flag == true)
    {
        return;
    }
    int i = find(in.begin(), in.end(), pre[root]) - in.begin();
    post1(root + 1, start, i - 1);
    post1(root + 1 + i - start, i + 1, end);
    if (flag == false)
    {
        cout << pre[root];
        flag = true;
    }
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
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> pre[i];
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    post1(0, 0, n - 1);
    return 0;
}