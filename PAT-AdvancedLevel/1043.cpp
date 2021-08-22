#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1010;
int n;
bool isMirror;
vector<int> pre, post;

void getPost(int root, int tail)
{
    if (root > tail)
        return;
    int i = root + 1, j = tail;
    if (!isMirror)
    {
        while (i <= tail && pre[root] > pre[i])
            i++;
        while (j > root && pre[root] <= pre[j])
            j--;
    }
    else
    {
        while (i <= tail && pre[root] <= pre[i])
            i++;
        while (j > root && pre[root] > pre[j])
            j--;
    }
    if (i - j != 1)
        return;
    getPost(root + 1, j);
    getPost(i, tail);
    post.push_back(pre[root]);
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
    for (int i = 0; i < n; ++i)
        cin >> pre[i];
    getPost(0, n - 1);
    if (post.size() != n)
    {
        isMirror = true;
        post.clear();
        getPost(0, n - 1);
    }
    if (post.size() == n)
    {
        cout << "YES\n"
             << post[0];
        for (int i = 1; i < post.size(); ++i)
            cout << " " << post[i];
    }
    else
        cout << "NO";
    return 0;
}