#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10010, M = 110;
typedef pair<string, int> PII;

int n, m;
struct Stu
{
    string card;
    int score;

    string level, site, date, num;

    bool operator<(const Stu &s) const
    {
        if (score != s.score)
            return score > s.score;
        return card < s.card;
    }
} stu[N];

bool cmp(const pair<string, int> &p1, const pair<string, int> &p2)
{
    if (p1.second != p2.second)
        return p1.second > p2.second;
    return p1.first < p2.first;
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
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> stu[i].card >> stu[i].score;
        stu[i].level = stu[i].card[0];
        stu[i].site = stu[i].card.substr(1, 3);
        stu[i].date = stu[i].card.substr(4, 6);
        stu[i].num = stu[i].card.substr(10, 3);
    }
    sort(stu, stu + n);
    int type;
    string term;
    for (int i = 1; i <= m; ++i)
    {
        cin >> type >> term;
        cout << "Case " << i << ": " << type << " " << term << "\n";
        if (type == 1)
        {
            vector<Stu> ans;
            for (int i = 0; i < n; ++i)
            {
                if (stu[i].level == term)
                {
                    ans.push_back(stu[i]);
                }
            }
            if (ans.size() == 0)
                cout << "NA\n";
            else
            {
                for (auto &i : ans)
                {
                    cout << i.card << " " << i.score << "\n";
                }
            }
        }
        else if (type == 2)
        {
            int nt = 0, ns = 0;
            for (int i = 0; i < n; ++i)
            {
                if (stu[i].site == term)
                {
                    nt++;
                    ns += stu[i].score;
                }
            }
            if (nt == 0)
                cout << "NA\n";
            else
                cout << nt << " " << ns << "\n";
        }
        else if (type == 3)
        {
            unordered_map<string, int> m;
            for (int i = 0; i < n; ++i)
            {
                if (stu[i].date == term)
                {
                    m[stu[i].site]++;
                }
            }
            vector<pair<string, int>> v(m.begin(), m.end());
            sort(v.begin(), v.end(), cmp);
            if (v.size() == 0)
                cout << "NA\n";
            else
            {
                for (auto &i : v)
                {
                    cout << i.first << " " << i.second << "\n";
                }
            }
        }
    }
    return 0;
}