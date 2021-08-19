#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 100010;

int n;
vector<int> st;
multiset<int> s1, s2;

void adjust()
{
    if (s1.size() - s2.size() == 2)
    {
        s2.insert(*s1.rbegin());
        s1.erase(prev(s1.end()));
    }
    else if (s1.size() - s2.size() == -1)
    {
        s1.insert(*s2.begin());
        s2.erase(s2.begin());
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
    while (n--)
    {
        string op;
        cin >> op;
        if (op == "Push")
        {
            int x;
            cin >> x;
            st.push_back(x);
            if (s2.empty() || x < *s1.rbegin())
                s1.insert(x);
            else
                s2.insert(x);
            adjust();
        }
        else if (op == "Pop")
        {
            if (st.size())
            {
                cout << st.back() << "\n";
                if (s1.count(st.back()))
                    s1.erase(s1.find(st.back()));
                else
                    s2.erase(s2.find(st.back()));
                adjust();
                st.pop_back();
            }
            else
                cout << "Invalid\n";
        }
        else
        {
            if (st.size())
            {
                cout << *s1.rbegin() << "\n";
            }
            else
                cout << "Invalid\n";
        }
    }

    return 0;
}