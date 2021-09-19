// #include <bits/stdc++.h>
// using namespace std;
// //#define LOCAL

// const int N = 10010;
// int n1, n2, n3;

// set<int, greater<int>> s1, s2, s3;

// int main()
// {
//     // ios::sync_with_stdio(0);
//     // cin.tie(0);
//     // cout.tie(0);
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     cin >> n1 >> n2 >> n3;
//     int x;
//     for (int i = 0; i < n1; ++i)
//     {
//         cin >> x;
//         s1.insert(x);
//     }
//     for (int i = 0; i < n2; ++i)
//     {
//         cin >> x;
//         s2.insert(x);
//     }
//     for (int i = 0; i < n3; ++i)
//     {
//         cin >> x;
//         s3.insert(x);
//     }
//     int minn = 0x3f3f3f3f;
//     vector<int> ans;
//     for (auto &i : s1)
//     {
//         for (auto &j : s2)
//         {
//             for (auto &k : s3)
//             {
//                 int temp = abs(i - j) + abs(i - k) + abs(j - k);
//                 vector<int> res;
//                 if (temp < minn)
//                 {
//                     minn = temp;
//                     res.push_back(i);
//                     res.push_back(j);
//                     res.push_back(k);
//                     ans = res;
//                 }
//                 else if (temp == minn)
//                 {
//                     if (res > ans)
//                     {
//                         ans = res;
//                     }
//                 }
//             }
//         }
//     }
//     printf("MinD(%d, %d, %d) = %d", ans[0], ans[1], ans[2], minn);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10010;

int na, nb, nc;
int a[N], b[N], c[N];

bool find_min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return true;
    return false;
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
    cin >> na >> nb >> nc;
    for (int i = 0; i < na; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + na);
    for (int i = 0; i < nb; ++i)
    {
        cin >> b[i];
    }
    sort(b, b + nb);
    for (int i = 0; i < nc; ++i)
    {
        cin >> c[i];
    }
    sort(c, c + nc);
    int mindis = 0x3f3f3f3f;
    int pa, pb, pc;
    vector<int> ans = {0, 0, 0};
    for (pa = 0, pb = 0, pc = 0; pa < na && pb < nb && pc < nc;)
    {
        int ta = a[pa], tb = b[pb], tc = c[pc];
        int dis = abs(ta - tb) + abs(ta - tc) + abs(tb - tc);
        if (dis <= mindis)
        {
            mindis = dis;
            ans = {ta, tb, tc};
        }
        if (find_min(ta, tb, tc))
        {
            pa++;
        }
        else if (find_min(tb, ta, tc))
        {
            pb++;
        }
        else
        {
            pc++;
        }
    }
    printf("MinD(%d, %d, %d) = %d", ans[0], ans[1], ans[2], mindis);
    return 0;
}