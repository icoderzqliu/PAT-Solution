/*** 
 * @Author: zqliu
 * @Date: 2021-05-09 17:11:41
 * @LastEditTime: 2021-05-09 18:50:56
 * @Description: PAT
 */
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
long long getNum(string s, long long radix)
{
	long long sum = 0;
	for (auto c : s)
	{
		int val = c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10;
		sum = sum * radix + val;
	}
	return sum;
}
int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
#ifdef LOCAL
	freopen("1010in.txt", "r", stdin);
	freopen("1010out.txt", "w", stdout);
#endif
	string s1, s2;
	int tag, maxR = 0;
	long long radix;
	cin >> s1 >> s2 >> tag >> radix;
	long long a = tag == 1 ? getNum(s1, radix) : getNum(s2, radix);
	s2 = tag == 1 ? s2 : s1;
	for (char c : s2)
	{
		if (c >= '0' && c <= '9')
		{
			maxR = maxR > (c - '0') ? maxR : (c - '0');
		}
		else
		{
			maxR = maxR > (c - 'a' + 10) ? maxR : (c - 'a' + 10);
		}
	}
	long long start = maxR + 1, end = a + 1;
	while (start <= end)
	{
		long long ans = (start + end) / 2;
		long long temp = getNum(s2, ans);
		if (start == end && temp != a)
			break;
		else if (temp == a)
		{
			cout << ans << endl;
			return 0;
		}
		else if (temp > a || temp < 0)
			end = ans;
		else
			start = ans + 1;
	}
	cout << "Impossible";
	return 0;
}
