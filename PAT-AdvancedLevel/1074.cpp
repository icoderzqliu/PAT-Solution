#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 100010;

int n, k, head = -1;
struct Node
{
    int address, data, next;
} nodes[N];

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &head, &n, &k);
    while (n--)
    {
        int add, val, nt;
        scanf("%d%d%d", &add, &val, &nt);
        nodes[add] = {add, val, nt};
    }
    vector<Node> lst;
    while (head != -1)
    {
        lst.push_back(nodes[head]);
        head = nodes[head].next;
    }
    // for (int i = k; i <= lst.size(); i += k)
    // {
    //     reverse(lst.begin() + i - k, lst.begin() + i);
    // }
    for (int i = 0; i < lst.size() - lst.size() % k; i += k)
    {
        reverse(lst.begin() + i, lst.begin() + i + k);
    }
    for (int i = 0; i < lst.size() - 1; ++i)
    {
        printf("%05d %d %05d\n", lst[i].address, lst[i].data, lst[i + 1].address);
    }
    printf("%05d %d -1", lst.back().address, lst.back().data);
    return 0;
}