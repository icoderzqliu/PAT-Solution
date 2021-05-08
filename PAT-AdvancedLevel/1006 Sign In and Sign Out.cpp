/*** 
 * @Author: zqliu
 * @Date: 2021-05-08 18:12:44
 * @LastEditTime: 2021-05-08 18:29:54
 * @Description: PAT
 */
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
int m;
string firstP,lastP;
int firstT=INT_MAX,lastT=-1;

int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
#ifdef LOCAL
	freopen("1006in.txt", "r", stdin);
	freopen("1006out.txt", "w", stdout);
#endif
	scanf("%d",&m);
	string id;
	int st,et;
	int sh,sm,ss,eh,em,es;
	while (m--)
	{
		cin>>id;
		getchar();
		scanf("%d:%d:%d %d:%d:%d",&sh,&sm,&ss,&eh,&em,&es);
		st=sh*3600+sm*60+ss;
		et=eh*3600+em*60+es;
		if(st<firstT){
			firstT=st;
			firstP=id;
		}
		if(et>lastT){
			lastT=et;
			lastP=id;
		}
	}
	cout<<firstP<<" "<<lastP;
	return 0;
}
