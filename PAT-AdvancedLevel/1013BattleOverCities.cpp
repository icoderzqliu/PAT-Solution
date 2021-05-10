/*** 
 * @Author: zqliu
 * @Date: 2021-05-10 21:09:13
 * @LastEditTime: 2021-05-10 21:52:18
 * @Description: PAT
 */
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1005;
int n, m, k;
vector<int> g[N];
bool visit[N] = {false};
void dfs(int v)
{
	visit[v] = true;
	for (int i : g[v])
	{
		if (!visit[i])
		{
			dfs(i);
		}
	}
}

int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
#ifdef LOCAL
	freopen("1013in.txt", "r", stdin);
	freopen("1013out.txt", "w", stdout);
#endif

	cin >> n >> m >> k;
	int u, v;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	while (k--)
	{
		cin >> u;
		fill(visit + 1, visit + n + 1, false);
		visit[u] = true;
		int num = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (!visit[i])
			{
				dfs(i);
				num++;
			}
		}
		cout << num - 1 << endl;
	}
	return 0;
}
