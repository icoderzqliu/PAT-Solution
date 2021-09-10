#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1010;
int n, m;

vector<int> h;

// void down(int u)
// {
//     int t = u;
//     if (u * 2 + 1 < n && h[u * 2 + 1] > h[t])
//         t = u * 2 + 1;
//     if (u * 2 + 2 < n && h[u * 2 + 2] > h[t])
//         t = u * 2 + 2;
//     if (t != u)
//     {
//         swap(h[t], h[u]);
//         down(t);
//     }
// }

void up(int u)
{
    while (u)
    {
        if (h[u] > h[(u - 1) / 2])
        {
            swap(h[(u - 1) / 2], h[u]);
        }
        u = (u - 1) / 2;
    }
}

void solve(string s)
{
    vector<string> v;
    stringstream ss(s);
    string t;
    while (ss >> t)
    {
        v.push_back(t);
    }
    int x, y;
    x = stoi(v[0]);
    if (v.back() == "root")
    {
        if (x == h[0])
            cout << 1;
        else
            cout << 0;
    }
    else if (v[3] == "are")
    {
        y = stoi(v[2]);
        int px = find(h.begin(), h.end(), x) - h.begin();
        int py = find(h.begin(), h.end(), y) - h.begin();
        int pxp = (px - 1) / 2, pyp = (py - 1) / 2;
        if (pxp == pyp && (px - py == 1 || py - px == 1))
        {
            cout << 1;
        }
        else
            cout << 0;
    }
    else if (v[3] == "parent")
    {
        y = stoi(v.back());
        int px = find(h.begin(), h.end(), x) - h.begin();
        int py = find(h.begin(), h.end(), y) - h.begin();
        if ((py - 1) / 2 == px)
        {
            cout << 1;
        }
        else
            cout << 0;
    }
    else if (v[3] == "left")
    {
        y = stoi(v.back());
        int px = find(h.begin(), h.end(), x) - h.begin();
        int py = find(h.begin(), h.end(), y) - h.begin();
        if (py * 2 + 1 == px)
        {
            cout << 1;
        }
        else
            cout << 0;
    }
    else if (v[3] == "right")
    {
        y = stoi(v.back());
        int px = find(h.begin(), h.end(), x) - h.begin();
        int py = find(h.begin(), h.end(), y) - h.begin();
        if (py * 2 + 2 == px)
        {
            cout << 1;
        }
        else
            cout << 0;
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
    cin >> n >> m;
    h.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
        up(i);
    }
    // for (int i = n / 2; i >= 0; --i)
    // {
    //     down(i);
    // }
    string s;
    getchar();
    for (int i = 0; i < m; ++i)
    {
        getline(cin, s);
        solve(s);
    }

    return 0;
}