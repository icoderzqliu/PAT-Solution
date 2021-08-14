#include <bits/stdc++.h>
using namespace std;
#define LOCAL
const int N = 510;
typedef pair<int, double> PID;

double cmax, dist, avgdist;
int n;
PID stations[N];

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("1033in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    scanf("%lf%lf%lf%d", &cmax, &dist, &avgdist, &n);
    for (int i = 0; i < n; ++i)
    {
        double price;
        int dis;
        scanf("%lf%d", &price, &dis);
        stations[i].first = dis;
        stations[i].second = price;
    }
    stations[n].first = dist;
    stations[n].second = 0;
    sort(stations, stations + n);
    double farest = cmax * avgdist;
    double cost = 0.0, currentTank = 0.0;
    if (stations[0].first > 0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    int currentIndex = 0;
    while (currentIndex < n)
    {
        int minIndex = -1;
        double minPrice = 1e6 * 1.0;
        for (int i = currentIndex + 1; i <= n && stations[i].first <= stations[currentIndex].first + farest; ++i)
        {
            if (minPrice >= stations[i].second)
            {
                minIndex = i;
                minPrice = stations[i].second;
            }
            if (stations[i].second < stations[currentIndex].second)
                break;
        }
        if (minIndex == -1)
        {
            double maxDist = stations[currentIndex].first + farest;
            printf("The maximum travel distance = %.2lf", maxDist);
            return 0;
        }
        double tempTank = (stations[minIndex].first - stations[currentIndex].first) / avgdist;
        if (stations[currentIndex].second > stations[minIndex].second)
        {
            cost += (tempTank - currentTank) * stations[currentIndex].second;
            currentTank = 0;
        }
        else
        {
            cost += (cmax - currentTank) * stations[currentIndex].second;
            currentTank = cmax - tempTank;
        }
        currentIndex = minIndex;
    }
    printf("%.2lf", cost);
    return 0;
}