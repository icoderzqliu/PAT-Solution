#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> PIS;
//#define LOCAL
const int N = 1010, K = 8 * N;

int n, k;
unordered_map<string, vector<PIS>> records;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    while (n--)
    {
        string id, st;
        int h, m, s;
        char c;
        cin >> id >> h >> c >> m >> c >> s >> st;
        records[id].push_back({3600 * h + 60 * m + s, st});
    }
    int maxt = 0;
    set<string> ids;
    vector<PIS> validRecords;
    for (auto &record : records)
    {
        string id = record.first;
        auto &r = record.second;
        sort(r.begin(), r.end());
        int t = 0;
        for (int i = 1; i < r.size(); ++i)
        {
            if (r[i].second == "out" and r[i - 1].second == "in")
            {
                validRecords.push_back(r[i - 1]);
                validRecords.push_back(r[i]);
                t += r[i].first - r[i - 1].first;
            }
        }
        if (t > maxt)
        {
            ids.clear();
            ids.insert(id);
            maxt = t;
        }
        else if (t == maxt)
        {
            ids.insert(id);
        }
    }
    sort(validRecords.begin(), validRecords.end());
    int ans = 0, i = 0;
    while (k--)
    {
        int h, m, s;
        char c;
        cin >> h >> c >> m >> c >> s;
        int t = h * 3600 + m * 60 + s;
        while (i < validRecords.size() and validRecords[i].first <= t)
        {
            validRecords[i].second == "in" ? ++ans : --ans;
            ++i;
        }
        cout << ans << "\n";
    }
    for (auto &id : ids)
    {
        cout << id << " ";
    }
    printf("%02d:%02d:%02d", maxt / 3600, maxt % 3600 / 60, maxt % 60);
    return 0;
}