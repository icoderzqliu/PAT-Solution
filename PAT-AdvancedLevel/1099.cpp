#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 110;

struct Node
{
    int data, l = -1, r = -1;
} tree[N];

int n, cnt;
int in[N];

void inOrder(int root)
{
    if (root == -1)
        return;
    inOrder(tree[root].l);
    tree[root].data = in[cnt++];
    inOrder(tree[root].r);
}

void levelOrder(int root)
{
    queue<int> q;
    q.push(root);

    while (q.size())
    {
        int t = q.front();
        q.pop();
        cout << (t == 0 ? "" : " ") << tree[t].data;
        if (tree[t].l != -1)
            q.push(tree[t].l);
        if (tree[t].r != -1)
            q.push(tree[t].r);
    }
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
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> tree[i].l >> tree[i].r;
    }
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    sort(in, in + n);
    inOrder(0);
    levelOrder(0);
    return 0;
}