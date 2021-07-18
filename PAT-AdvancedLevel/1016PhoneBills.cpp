/*** 
 * @Author: zqliu
 * @Date: 2021-06-30 11:29:05
 * @LastEditTime: 2021-06-30 14:27:57
 */
#include <bits/stdc++.h>
using namespace std;
#define LOCAL

struct Record
{
	int M, D, H, m;
	int tag;
	Record(int a, int b, int c, int d, int t) : M(a), D(b), H(c), m(d), tag(t) {}
	bool operator<(const Record &r) const
	{
		return D * 24 * 60 + H * 60 + m < r.D * 24 * 60 + r.H * 60 + r.m;
	}
};

map<string, vector<Record>> R;
int toll[25] = {0};
int rate[25] = {0};
double bills;

void tolls(Record &a, Record &b)
{
	printf("%02d:%02d:%02d %02d:%02d:%02d ", a.D, a.H, a.m, b.D, b.H, b.m);
	printf("%d ", (b.D - a.D) * 24 * 60 + (b.H - a.H) * 60 + b.m - a.m);
	double x = (b.D - a.D) * rate[24] * 60 + (rate[b.H] - rate[a.H]) * 60 + toll[b.H] * b.m - toll[a.H] * a.m;
	printf("$%.2lf\n", x / 100.0);
	bills += x;
}
int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
#ifdef LOCAL
	freopen("1016in.txt", "r", stdin);
	freopen("1016out.txt", "w", stdout);
#endif
	for (int i = 0; i <= 23; i++)
	{
		cin >> toll[i];
		rate[i + 1] += rate[i] + toll[i];
	}
	int T;
	cin >> T;
	while (T--)
	{
		string name, tag;
		int t;
		int M, D, H, m;
		cin >> name;
		scanf("%d:%d:%d:%d", &M, &D, &H, &m);
		cin >> tag;
		t = tag == "on-line" ? 1 : 0;
		R[name].push_back(Record(M, D, H, m, t));
	}

	for (auto r : R)
	{
		/* code */
		bills = 0;
		int flag = 0;
		sort(r.second.begin(), r.second.end());
		int n = r.second.size();
		for (int i = 0; i < n; ++i)
		{
			if (r.second[i].tag == 1)
			{
				int j = i + 1;
				while (j < n && r.second[j].tag)
				/* 连续online表示未接通，跳过 */
				{
					++i;
					++j;
				}
				if (j < n)
				{
					if (!flag)
					{
						cout << r.first << " ";
						printf("%02d\n", r.second[i].M);
					}
					tolls(r.second[i], r.second[j]);
					flag = 1;
					++i;
				}
			}
		}
		if (flag)
		{
			printf("Total amount: $%.2lf\n", bills / 100.0);
		}
	}
	return 0;
}
