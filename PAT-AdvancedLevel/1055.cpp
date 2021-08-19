#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 100010, K = 1010, INF = 0x3f3f3f3f;

int n, k;
struct Person
{
    string name;
    int age, worth;

    bool operator<(const Person &p) const
    {
        if (worth != p.worth)
            return worth > p.worth;
        if (age != p.age)
            return age < p.age;
        if (name != p.name)
            return name < p.name;
    }
};

vector<Person> people;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        string name;
        int age, worth;
        cin >> name >> age >> worth;
        people.push_back({name, age, worth});
    }
    sort(people.begin(), people.end());
    for (int i = 1; i <= k; ++i)
    {
        cout << "Case #" << i << ":\n";
        int m, amin, amax;
        cin >> m >> amin >> amax;
        int cnt = 0;
        for (int j = 0; j < people.size(); ++j)
        {
            if (people[j].age >= amin && people[j].age <= amax)
            {
                cout << people[j].name << " " << people[j].age << " " << people[j].worth << "\n";
                cnt++;
            }
            if (cnt == m)
            {
                break;
            }
        }
        if (cnt == 0)
            cout << "None\n";
    }
    return 0;
}