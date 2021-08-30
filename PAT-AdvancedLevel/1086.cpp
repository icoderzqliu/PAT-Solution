#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
int n;

stack<int> st;
vector<int> inorder, preorder, postorder;

void getPost(int root, int left, int right)
{
    if (left > right)
        return;
    int i = find(inorder.begin(), inorder.end(), preorder[root]) - inorder.begin();
    getPost(root + 1, left, i - 1);
    getPost(root + 1 + i - left, i + 1, right);
    postorder.push_back(preorder[root]);
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
    string op;
    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> op;
        int x;
        if (op == "Push")
        {
            cin >> x;
            st.push(x);
            preorder.push_back(x);
        }
        else
        {
            inorder.push_back(st.top());
            st.pop();
        }
    }
    getPost(0, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        cout << postorder[i] << (i == n - 1 ? "" : " ");
    }
    return 0;
}