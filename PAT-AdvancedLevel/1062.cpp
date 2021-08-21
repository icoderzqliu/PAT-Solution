#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 100010;
int n, l, h;
struct Person
{
    string id;
    int virtue, talent;
    bool operator<(const Person &p) const
    {
        if (virtue + talent != p.virtue + p.talent)
            return virtue + talent > p.virtue + p.talent;
        if (virtue != p.virtue)
            return virtue > p.virtue;
        return id < p.id;
    }
};
vector<Person> sages, nobles, fools, remains;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> l >> h;
    string id;
    int virtue, talent;
    for (int i = 0; i < n; ++i)
    {
        cin >> id >> virtue >> talent;
        Person p = {id, virtue, talent};
        if (talent >= l && virtue >= l)
        {
            if (virtue >= h && talent >= h)
            {
                sages.push_back(p);
            }
            else if (talent < h && virtue >= h)
            {
                nobles.push_back(p);
            }
            else if (talent < h && virtue < h && virtue >= talent)
            {
                fools.push_back(p);
            }
            else
            {
                remains.push_back(p);
            }
        }
    }
    cout << (sages.size() + nobles.size() + fools.size() + remains.size()) << "\n";
    sort(sages.begin(), sages.end());
    sort(nobles.begin(), nobles.end());
    sort(fools.begin(), fools.end());
    sort(remains.begin(), remains.end());
    for (auto &i : sages)
    {
        cout << i.id << " " << i.virtue << " " << i.talent << "\n";
    }
    for (auto &i : nobles)
    {
        cout << i.id << " " << i.virtue << " " << i.talent << "\n";
    }
    for (auto &i : fools)
    {
        cout << i.id << " " << i.virtue << " " << i.talent << "\n";
    }
    for (auto &i : remains)
    {
        cout << i.id << " " << i.virtue << " " << i.talent << "\n";
    }
    return 0;
}
