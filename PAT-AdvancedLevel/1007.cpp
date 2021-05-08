/*** 
 * @Author: zqliu
 * @Date: 2021-05-08 18:38:37
 * @LastEditTime: 2021-05-08 20:23:58
 * @Description: 1007 Maximum Subsequence Sum
 */
// 最大子序和
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1e5 + 2;
int k;
int a[N];
int dp[N];		// dp[i]表示i位置的最大子序和
int s[N], e[N]; // s[i]表示i位置的开始,e[i]表示结束
int maxx = INT_MIN, sm, em;
int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
#ifdef LOCAL
	freopen("1007in.txt", "r", stdin);
	freopen("1007out.txt", "w", stdout);
#endif
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> a[i];
		dp[i] = a[i];
		s[i] = e[i] = i;
	}
	maxx=dp[0];
	for (int i = 1; i < k; ++i)
	{
		if (a[i] > dp[i - 1] + a[i])
		{
			s[i] = e[i] = i;
		}
		else
		{
			dp[i] = dp[i - 1] + a[i];
			s[i] = s[i - 1];
			e[i] = i;
		}
		if (maxx < dp[i])
		{
			maxx = dp[i];
			sm = s[i];
			em = e[i];
		}
	}
	if (maxx < 0)
	{
		cout << "0 " << a[0] << " " << a[k - 1];
	}
	else
		cout << maxx << " " << a[sm] << " " << a[em];
	return 0;
}
