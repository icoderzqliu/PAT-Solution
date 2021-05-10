/*** 
 * @Author: zqliu
 * @Date: 2021-05-10 19:56:25
 * @LastEditTime: 2021-05-10 21:06:30
 * @Description: PAT
 */
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 2002;
int n, m;
struct Student
{
	int id;
	int C;
	int M;
	int E;
	int A;
} students[N];
unordered_map<int, pair<int, char>> mp;

int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
#ifdef LOCAL
	freopen("1012in.txt", "r", stdin);
	freopen("1012out.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> students[i].id >> students[i].C >> students[i].M >> students[i].E;
		students[i].A = (students[i].C + students[i].M + students[i].E) / 3;
		mp[students[i].id].first = n + 1;
	}
	students[0].A = students[0].C = students[0].M = students[0].E = -1;
	sort(students + 1, students + 1 + n, [](const Student &s1, const Student &s2) { return s1.A > s2.A; });
	int temp = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (students[i].A != students[i-1].A)
		{
			temp = i;
		}
		mp[students[i].id].first = temp;
		mp[students[i].id].second = 'A';
	}
	sort(students + 1, students + 1 + n, [](const Student &s1, const Student &s2) { return s1.C > s2.C; });
	temp = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (students[i].C != students[i - 1].C)
		{
			temp = i;
		}
		if (temp < mp[students[i].id].first)
		{
			mp[students[i].id].first = temp;
			mp[students[i].id].second = 'C';
		}
	}
	sort(students + 1, students + 1 + n, [](const Student &s1, const Student &s2) { return s1.M > s2.M; });
	temp = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (students[i].M != students[i - 1].M)
		{
			temp = i;
		}
		if (temp < mp[students[i].id].first)
		{
			mp[students[i].id].first = temp;
			mp[students[i].id].second = 'M';
		}
	}
	sort(students + 1, students + 1 + n, [](const Student &s1, const Student &s2) { return s1.E > s2.E; });
	temp = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (students[i].E != students[i - 1].E)
		{
			temp = i;
		}
		if (temp < mp[students[i].id].first)
		{
			mp[students[i].id].first = temp;
			mp[students[i].id].second = 'E';
		}
	}
	while (m--)
	{
		int query;
		cin >> query;
		if (mp.find(query) != mp.end())
		{
			cout << mp[query].first << " " << mp[query].second << endl;
		}
		else
		{
			cout << "N/A" << endl;
		}
	}

	return 0;
}
