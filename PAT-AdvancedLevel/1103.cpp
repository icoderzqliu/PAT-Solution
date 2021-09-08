#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
int n, k, p;
vector<int> ans, temp, pows;

int s;

void dfs(int nn, int kk, int num, int sum)
{
    if (kk == 0 and nn == 0 and sum > s)
    {
        ans = temp;
        s = sum;
        return;
    }
    if (kk <= 0 or nn <= 0 or num <= 0)
        return;
    temp.push_back(num);
    dfs(nn - pows[num], kk - 1, num, sum + num);
    temp.pop_back();
    dfs(nn, kk, num - 1, sum);
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
    cin >> n >> k >> p;
    int temp = 0, index = 1;
    while (temp <= n)
    {
        pows.push_back(temp);
        temp = pow(index, p);
        index++;
    }
    dfs(n, k, pows.size() - 1, 0);
    if (ans.empty())
    {
        cout << "Impossible";
        return 0;
    }
    cout << n << " = " << ans[0] << "^" << p;
    for (int i = 1; i < ans.size(); ++i)
    {
        cout << " + " << ans[i] << "^" << p;
    }
    return 0;
}
