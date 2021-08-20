#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
long n;

map<long, long> factor;
vector<long> prime;

void getPrime(long x = 100000)
{
    vector<bool> vis(x + 1, false);
    for (long i = 2; i <= x; ++i)
    {
        if (!vis[i])
            prime.push_back(i);
        for (long j = 0; j < prime.size() && prime[j] * i <= x; ++j)
        {
            vis[prime[j] * i] = true;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

void getFactor(long x)
{
    getPrime();
    for (long i : prime)
    {
        while (x % i == 0)
        {
            factor[i]++;
            x /= i;
        }
        if (x == 1)
            break;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    if (n == 1)
    {
        cout << "1=1";
        return 0;
    }
    getFactor(n);
    cout << n << "=";
    for (auto it = factor.begin(); it != factor.end(); ++it)
    {
        cout << (it == factor.begin() ? "" : "*") << it->first;
        if (factor[it->first] > 1)
        {
            cout << "^" << it->second;
        }
    }
    return 0;
}