/*** 
 * @Author: zqliu
 * @Date: 2021-05-08 16:10:49
 * @LastEditTime: 2021-05-08 17:37:03
 * @Description: PAT
 */
#include <bits/stdc++.h>
using namespace std;
#define LOCAL
const int N = 105;
struct Node
{
	int lay = -1;
	int father;
	vector<int> child;
} node[N];

int n, m; // n总结点数，m非叶子结点数
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	freopen("1004in.txt", "r", stdin);
	freopen("1004out.txt", "w", stdout);
#endif
	cin >> n >> m;
	int id, k, childId;
	node[1].lay = 0;
	node[1].father = 1;
	for (int i = 1; i <= m; i++)
	{
		cin >> id >> k;
		while (k--)
		{
			cin >> childId;
			node[id].child.push_back(childId);
			node[childId].father = id;
		}
	}
	int i = 1;
	while (i)
	{
		i = 0;
		for (int j = 1; j <= n; ++j)
		{
			if ((node[node[j].father].lay != -1) && node[j].lay == -1)
			{
				node[j].lay = node[node[j].father].lay + 1;
			}
			else if (node[node[j].father].lay == -1)
				i++;
		}
	}
	map<int, int> mp;
	int maxLay = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (node[i].lay > maxLay)
		{
			maxLay = node[i].lay;
		}
		if (node[i].child.size() == 0)
			mp[node[i].lay]++;
	}
	for (int i = 0; i <= maxLay; ++i)
	{
		if (i < maxLay)
			cout << mp[i] << ' ';
		else
		{
			cout << mp[i];
		}
	}
	return 0;
}
