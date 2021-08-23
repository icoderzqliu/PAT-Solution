#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 30;
int n;

struct Node
{
    int val;
    Node *left, *right;
};

Node *rotateLeft(Node *root)
{
    Node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}

Node *rotateRight(Node *root)
{
    Node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}

Node *rotateLeftRight(Node *root)
{
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

Node *rotateRightLeft(Node *root)
{
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

int getHeight(Node *root)
{
    if (root == NULL)
        return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node();
        root->val = val;
        root->left = root->right = NULL;
    }
    else if (val < root->val)
    {
        root->left = insert(root->left, val);
        if (getHeight(root->left) - getHeight(root->right) == 2)
        {
            root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
        }
    }
    else
    {
        root->right = insert(root->right, val);
        if (getHeight(root->left) - getHeight(root->right) == -2)
        {
            root = val >= root->right->val ? rotateLeft(root) : rotateRightLeft(root);
        }
    }
    return root;
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
    Node *root = NULL;
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    cout << root->val;
    return 0;
}