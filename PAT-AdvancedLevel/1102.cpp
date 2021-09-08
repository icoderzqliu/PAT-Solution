#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 20;

int n;
struct Node
{
    int l = -1, r = -1, p = -1;
} nodes[N];

bool flag;

void trans(int root)
{
    if (root == -1)
        return;
    trans(nodes[root].l);
    trans(nodes[root].r);
    int t = nodes[root].l;
    nodes[root].l = nodes[root].r;
    nodes[root].r = t;
}

void levelOrder(int root)
{
    queue<int> q;
    q.push(root);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        cout << (t == root ? "" : " ") << t;
        if (nodes[t].l != -1)
            q.push(nodes[t].l);
        if (nodes[t].r != -1)
            q.push(nodes[t].r);
    }
}

void inOrder(int root)
{
    if (root == -1)
        return;
    inOrder(nodes[root].l);
    cout << (flag ? " " : "") << root;
    flag = true;
    inOrder(nodes[root].r);
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
        string s;
        cin >> s;
        if (s != "-")
        {
            int t = stoi(s);
            nodes[i].l = t;
            nodes[t].p = i;
        }
        cin >> s;
        if (s != "-")
        {
            int t = stoi(s);
            nodes[i].r = t;
            nodes[t].p = i;
        }
    }
    int root = 0;
    while (nodes[root].p != -1)
    {
        root = nodes[root].p;
    }
    trans(root);
    levelOrder(root);
    cout << "\n";
    inOrder(root);
    return 0;
}