#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
int n;
struct Student
{
    string name;
    string id;
    int grade;
    bool operator<(const Student &s) const
    {
        return grade < s.grade;
    }
};

vector<Student> Fstudents, Mstudents;

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
    for (int i = 0; i < n; ++i)
    {
        string name, id;
        char gender;
        int grade;
        cin >> name >> gender >> id >> grade;
        if (gender == 'F')
        {
            Fstudents.push_back({name, id, grade});
        }
        else
            Mstudents.push_back({name, id, grade});
    }
    sort(Fstudents.begin(), Fstudents.end());
    sort(Mstudents.begin(), Mstudents.end());

    if (Fstudents.size())
    {
        Student f = Fstudents.back();
        cout << f.name << ' ' << f.id << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    if (Mstudents.size())
    {
        Student m = Mstudents.front();
        cout << m.name << ' ' << m.id << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    if (Fstudents.size() && Mstudents.size())
    {
        cout << Fstudents.back().grade - Mstudents.front().grade;
    }
    else
    {
        cout << "NA";
    }
    return 0;
}