/*** 
 * @Author: zqliu
 * @Date: 2021-05-09 16:07:57
 * @LastEditTime: 2021-05-09 16:21:11
 * @Description: PAT
 */
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int UPTIME = 6;
const int DOWNTIME = 4;
const int STOPTIME = 5;

int request[101];

int n, sum;
int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
#ifdef LOCAL
	freopen("1008in.txt", "r", stdin);
	freopen("1008out.txt", "w", stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> request[i];
		sum += ((request[i] - request[i - 1]) > 0) ? UPTIME * (request[i] - request[i - 1]) : DOWNTIME * (request[i - 1] - request[i]);
		sum += STOPTIME;
	}
	cout << sum;
	return 0;
}
