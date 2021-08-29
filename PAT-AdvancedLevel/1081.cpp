#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
//#define LOCAL
const int N = 110;

int n;

struct Fenshu
{
    LL fz = 0, fm = 1;
} number[N];

LL gcd(LL a, LL b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        int p = s.find('/');
        int fz, fm;
        fz = stoll(s.substr(0, p));
        fm = stoll(s.substr(p + 1));
        number[i].fz = fz / gcd(abs(fz), fm);
        number[i].fm = fm / gcd(abs(fz), fm);
    }
    Fenshu f;
    for (int i = 0; i < n; ++i)
    {
        int fm, fz;
        fm = f.fm * number[i].fm / gcd(f.fm, number[i].fm);
        fz = f.fz * fm / f.fm + number[i].fz * fm / number[i].fm;
        f.fm = fm;
        f.fz = fz;
    }
    if (f.fz < 0)
    {
        cout << "-";
        f.fz = abs(f.fz);
    }
    int fz = f.fz, fm = f.fm;
    f.fz = fz / gcd(fz, fm);
    f.fm = fm / gcd(fz, fm);
    int q = f.fz / f.fm;
    if (f.fz % f.fm == 0)
    {
        cout << q;
    }
    else if (q == 0)
    {
        cout << f.fz << "/" << f.fm;
    }
    else
    {
        cout << q << " " << f.fz - q * f.fm << "/" << f.fm;
    }
    return 0;
}