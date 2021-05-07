#include <bits/stdc++.h>
using namespace std;
//#define DEBUG

int main()
{
#ifdef DEBUG
    freopen("1002in.txt", "r", stdin);
    freopen("1002out.txt", "w", stdout);
#endif
    int cnt1, cnt2;
    map<int, double,greater<int>> ma, mb;
    cin >> cnt1;
    int exp;
    double coe;
    for (int i = 0; i < cnt1; ++i)
    {

        cin >> exp >> coe;
        ma[exp] = coe;
    }
    cin >> cnt2;
    for (int i = 0; i < cnt2; ++i)
    {
        cin >> exp >> coe;
        mb[exp] = coe;
    }
    for (auto &i : mb)
    {
        if (ma.find(i.first) != ma.end())
        {
            ma[i.first] += i.second;
        }
        else
        {
            ma[i.first] = i.second;
        }
    }
    for (auto it=ma.begin();it!=ma.end();)
    {
        if(it->second==0){
            it=ma.erase(it);
        }else{
            it++;
        }
    }
    printf("%d", ma.size());
    for (auto &i : ma)
    {
        printf(" %d %.1lf", i.first, i.second);
    }

    return 0;
}
