/*** 
 * @Author: zqliu
 * @Date: 2021-05-08 17:58:39
 * @LastEditTime: 2021-05-08 18:11:55
 * @Description: PAT
 */
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
string s;
map<int, string> mp = {{0, "zero"},
					   {1, "one"},
					   {2, "two"},
					   {3, "three"},
					   {4, "four"},
					   {5, "five"},
					   {6, "six"},
					   {7, "seven"},
					   {8, "eight"},
					   {9, "nine"},
					   {10, "ten"}};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	freopen("1005in.txt", "r", stdin);
	freopen("1005out.txt", "w", stdout);
#endif
	cin >> s;
	if(s=="0"){
		cout<<"zero";
		return 0;
	}
	long long sum = 0;
	for (char c : s)
	{
		sum += c - '0';
	}
	vector<string> v;
	while (sum)
	{
		v.push_back(mp[sum % 10]);
		sum /= 10;
	}
	for (int i = v.size() - 1; i >= 0; --i)
	{
		if (i != 0)
			cout << v[i] << " ";
		else
		{
			cout << v[i];
		}
	}
	return 0;
}
