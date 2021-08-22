// #include <bits/stdc++.h>
// using namespace std;
// //#define LOCAL
// const int N = 40;

// int n;
// int post[N], in[N];
// map<int, int> level;

// struct BTNode
// {
//     int val;
//     BTNode *left, *right;
// };

// BTNode *buildTree(int root, int start, int end)
// {
//     if (start > end)
//         return nullptr;
//     int i = start;
//     while (i < end && in[i] != post[root])
//     {
//         i++;
//     }
//     BTNode *t = new BTNode();
//     t->val = post[root];
//     t->left = buildTree(root - (end - i + 1), start, i - 1);
//     t->right = buildTree(root - 1, i + 1, end);
//     return t;
// }

// void levelOrder(BTNode *root)
// {
//     queue<BTNode *> q;
//     q.push(root);
//     bool space = false;
//     while (q.size())
//     {
//         BTNode *t = q.front();
//         q.pop();
//         cout << (space ? " " : "") << t->val;
//         if (t->left)
//             q.push(t->left);
//         if (t->right)
//             q.push(t->right);
//         space = true;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     cin >> n;
//     for (int i = 0; i < n; ++i)
//         cin >> post[i];
//     for (int i = 0; i < n; ++i)
//         cin >> in[i];
//     levelOrder(buildTree(n - 1, 0, n - 1));
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 40;

int n;
vector<int> post, in;
map<int, int> level;

void buildTree(vector<int> &post, vector<int> &in, int root, int start, int end, int index)
{
    if (start > end)
        return;
    level[index] = post[root];
    int i = find(in.begin(), in.end(), post[root]) - in.begin();
    buildTree(post, in, root - 1 - end + i, start, i - 1, index * 2 + 1);
    buildTree(post, in, root - 1, i + 1, end, index * 2 + 2);
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
    post.resize(n);
    in.resize(N);
    for (int i = 0; i < n; ++i)
        cin >> post[i];
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    buildTree(post, in, n - 1, 0, n - 1, 0);
    for (auto it = level.begin(); it != level.end(); ++it)
    {
        cout << it->second;
        cout << (it == prev(level.end()) ? "" : " ");
    }
    return 0;
}