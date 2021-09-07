#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 100010;

struct Node
{
    int address, key, next;
} nodes[N];

int n, head;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> head >> n;
    for (int i = 0; i < n; ++i)
    {
        int add, key, ne;
        cin >> add >> key >> ne;
        nodes[add] = {add, key, ne};
    }
    vector<Node> valid, cut;
    
    set<int> keys;
    for (int i = head; i != -1; i = nodes[i].next)
    {
        if (keys.find(abs(nodes[i].key)) == keys.end())
        {
            valid.push_back(nodes[i]);
            keys.insert(abs(nodes[i].key));
        }
        else
        {
            cut.push_back(nodes[i]);
        }
    }
    if (valid.size())
    {
        for (int i = 0; i < valid.size() - 1; ++i)
        {
            printf("%05d %d %05d\n", valid[i].address, valid[i].key, valid[i + 1].address);
        }
        printf("%05d %d -1\n", valid.back().address, valid.back().key);
    }
    if (cut.size())
    {
        for (int i = 0; i < cut.size() - 1; ++i)
        {
            printf("%05d %d %05d\n", cut[i].address, cut[i].key, cut[i + 1].address);
        }
        printf("%05d %d -1\n", cut.back().address, cut.back().key);
    }
    return 0;
}