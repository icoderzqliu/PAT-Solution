/*** 
 * @Author: zqliu
 * @Date: 2021-05-10 19:39:27
 * @LastEditTime: 2021-05-10 21:57:08
 * @Description: PAT
 */
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
double g[3][3]; // g[i][j]表示第i场比赛结果j的赔率
double maxx[3]; // maxx[i]表示第i场比赛赔率最高的值
int maxc[3];	// maxc[i]表示第i场比赛最高赔率对应的结果
int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
#ifdef LOCAL
	freopen("1011in.txt", "r", stdin);
	freopen("1011out.txt", "w", stdout);
#endif
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> g[i][j];
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		maxx[i] = g[i][0];
		maxc[i] = 0;
		for (int j = 1; j < 3; ++j)
		{
			if (g[i][j] > maxx[i])
			{
				maxx[i] = g[i][j];
				maxc[i] = j;
			}
		}
	}
	double profit = (maxx[0] * maxx[1] * maxx[2]*0.65 - 1) * 2;
	for (int i = 0; i < 3; ++i)
	{
		if (maxc[i] == 0)
		{
			cout << "W ";
		}
		else if (maxc[i] == 1)
		{
			cout << "T ";
		}
		else
		{
			cout << "L ";
		}
	}
	printf("%.2lf", profit);
	return 0;
}
