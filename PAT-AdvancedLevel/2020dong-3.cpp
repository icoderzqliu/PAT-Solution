#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10010;

int n, k;

int depth;
int father[N];
unordered_map<int, int> depnum;

void solve(string s)
{
    int dep = s.find_first_not_of(' ');
    int num = stoi(s.substr(dep));
    depnum[dep] = num;
    if (num != 0)
        father[num] = depnum[dep - 1];
}

void query(string s)
{
    int dest = stoi(s);
    if (dest == 0)
    {
        cout << "0000";
        return;
    }
    if (father[dest] == -1)
    {
        printf("Error: %04d is not found.", dest);
        return;
    }
    vector<int> path;
    while (dest != -1)
    {
        path.push_back(dest);
        dest = father[dest];
    }
    for (int i = path.size() - 1; i >= 0; --i)
    {
        printf("%04d", path[i]);
        if (i != 0)
            printf("->");
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
    memset(father, -1, sizeof father);
    getchar();
    for (int i = 0; i < n; ++i)
    {
        string filename;
        getline(cin, filename);
        solve(filename);
    }
    cin >> k;
    string q;
    for (int i = 0; i < k; ++i)
    {
        cin >> q;
        query(q);
        cout << (i == k - 1 ? "" : "\n");
    }
    return 0;
}