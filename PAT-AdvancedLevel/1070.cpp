#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1010;

int n;
double d;
struct Yuebing
{
    double amount, price, danjia;
    bool operator<(const Yuebing &y) const
    {
        return danjia > y.danjia;
    }
} yuebings[N];

double profit;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> d;
    for (int i = 0; i < n; ++i)
        cin >> yuebings[i].amount;
    for (int i = 0; i < n; ++i)
    {
        cin >> yuebings[i].price;
        yuebings[i].danjia = yuebings[i].price / yuebings[i].amount;
    }
    sort(yuebings, yuebings + n);
    for (int i = 0; i < n; ++i)
    {
        if (yuebings[i].amount <= d)
        {
            profit += yuebings[i].price;
            d -= yuebings[i].amount;
        }
        else
        {
            profit += yuebings[i].danjia * d;
            break;
        }
    }
    printf("%.2lf", profit);
    return 0;
}
