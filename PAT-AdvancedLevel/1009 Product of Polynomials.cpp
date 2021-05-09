/*** 
 * @Author: zqliu
 * @Date: 2021-05-09 16:22:25
 * @LastEditTime: 2021-05-09 17:09:45
 * @Description: PAT
 */
#include <bits/stdc++.h>
using namespace std;
#define LOCAL
int k1, k2;
map<int, double, greater<int>> mp1;
map<int, double, greater<int>> mp2;
map<int, double, greater<int>> mp3;

int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
#ifdef LOCAL
	freopen("1009in.txt", "r", stdin);
	freopen("1009out.txt", "w", stdout);
#endif
	int exp;
	double cof;
	scanf("%d", &k1);
	for (int i = 1; i <= k1; ++i)
	{
		scanf("%d%lf", &exp, &cof);
		mp1[exp] = cof;
	}
	scanf("%d", &k2);
	for (int i = 1; i <= k2; ++i)
	{
		scanf("%d%lf", &exp, &cof);
		mp2[exp] = cof;
	}
	for (auto &m1 : mp1)
	{
		for (auto &m2 : mp2)
		{
			mp3[m1.first + m2.first] += m1.second * m2.second;
		}
	}
	for (auto it = mp3.begin(); it != mp3.end();)
	{
		if (it->second == 0)
		{
			it = mp3.erase(it);
		}
		else
			it++;
	}
	printf("%d", mp3.size());
	for (auto &m3 : mp3)
	{
		printf(" %d %.1lf", m3.first, m3.second);
	}
	return 0;
}
