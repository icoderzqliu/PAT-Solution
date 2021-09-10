#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 2020;

struct Section
{
    int st, ed;

    bool operator<(const Section &s) const
    {
        return ed < s.ed;
    }
} sec[N];

int n;

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
        int hh, mm, ss;
        int st, ed;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        st = hh * 3600 + mm * 60 + ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        ed = hh * 3600 + mm * 60 + ss;
        sec[i] = {st, ed};
    }
    sort(sec, sec + n);
    int ed = -1, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (sec[i].st >= ed)
        {
            ans++;
            ed = sec[i].ed;
        }
    }
    printf("%d", ans);
    return 0;
}