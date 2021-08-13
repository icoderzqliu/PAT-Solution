#include <bits/stdc++.h>
using namespace std;
#define LOCAL
const int N = 100010;
int n, c;

struct Student
{
    string id;
    string name;
    int score;
} students[N];

bool cmp1(const Student &s1, const Student &s2)
{
    return s1.id < s2.id;
}

bool cmp2(const Student &s1, const Student &s2)
{
    return s1.name == s2.name ? s1.id < s2.id : s1.name < s2.name;
}

bool cmp3(const Student &s1, const Student &s2)
{
    return s1.score == s2.score ? s1.id < s2.id : s1.score < s2.score;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("1028in.txt", "r", stdin);
    // freopen("1028out.txt", "w", stdout);
#endif
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
    {
        string id, name;
        int score;
        cin >> id >> name >> score;
        students[i] = {id, name, score};
    }
    if (c == 1)
        sort(students, students + n, cmp1);
    else if (c == 2)
        sort(students, students + n, cmp2);
    else
        sort(students, students + n, cmp3);
    for (int i = 0; i < n; ++i)
    {
        if (i != n - 1)
            cout << students[i].id << ' ' << students[i].name << ' ' << students[i].score << endl;
        else
            cout << students[i].id << ' ' << students[i].name << ' ' << students[i].score;
    }
    return 0;
}