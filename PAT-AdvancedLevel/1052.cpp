// #include <bits/stdc++.h>
// using namespace std;
// //#define LOCAL
// const int N = 100010;
// int n, head;
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     vector<array<int, 2>> input(N, {-1, -1});
//     cin >> n >> head;
//     if (head == -1)
//     {
//         cout << "0 -1";
//         return 0;
//     }
//     int address, key, nt;
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> address >> key >> nt;
//         input[address] = {key, nt};
//     }
//     vector<int> lst;
//     while (head != -1)
//     {
//         lst.push_back(head);
//         head = input[head][1];
//     }
//     sort(lst.begin(), lst.end(), [&input](int a, int b) { return input[a][0] < input[b][0]; });
//     cout << lst.size() << ' ' << setfill('0') << setw(5) << lst[0] << "\n";
//     for (int i = 0; i < lst.size() - 1; ++i)
//     {
//         cout << setw(5) << lst[i] << " " << input[lst[i]][0] << " " << setw(5) << lst[i + 1] << "\n";
//     }
//     cout << setw(5) << lst.back() << " " << input[lst.back()][0] << " -1\n";
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 100010;
struct Node
{
    int address, key, ne;
    bool operator<(const Node &s) const
    {
        return key < s.key;
    }
} nodes[N];

int n, head;
vector<Node> ans;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &head);
    int add, key, nt;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &add, &key, &nt);
        nodes[add] = {add, key, nt};
    }
    for (int i = head; i != -1; i = nodes[i].ne)
    {
        ans.push_back(nodes[i]);
    }
    sort(ans.begin(), ans.end());
    if (ans.size() == 0)
    {
        cout << "0 -1\n";
        return 0;
    }
    printf("%d %05d\n", ans.size(), ans[0].address);
    for (int i = 0; i < ans.size() - 1; ++i)
    {
        printf("%05d %d %05d\n", ans[i].address, ans[i].key, ans[i + 1].address);
    }
    printf("%05d %d -1\n", ans.back().address, ans.back().key);
    return 0;
}
