#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 1010;

struct Book
{
    string id, title, author, words, publisher, year;
    vector<string> keys;

    bool operator<(const Book &b) const
    {
        return id < b.id;
    }
};

int n, m;
vector<Book> v;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    getchar();
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        string id, title, author, words, publisher, year;
        getline(cin, id);
        getline(cin, title);
        getline(cin, author);
        getline(cin, words);
        getline(cin, publisher);
        getline(cin, year);
        v[i] = {id, title, author, words, publisher, year};
        stringstream ss(words);
        string key;
        while (ss >> key)
        {
            v[i].keys.push_back(key);
        }
    }
    sort(v.begin(), v.end());
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        vector<Book> ans;
        string num, query;
        cin >> num;
        getline(cin, query);
        cout << num << query << endl;
        while (query[0] == ' ')
        {
            query.erase(0, 1);
        }
        if (num[0] == '1')
        {
            for (auto &i : v)
            {
                if (i.title == query)
                {
                    ans.push_back(i);
                }
            }
        }
        if (num[0] == '2')
        {
            for (auto &i : v)
            {
                if (i.author == query)
                {
                    ans.push_back(i);
                }
            }
        }
        if (num[0] == '3')
        {
            for (auto &i : v)
            {
                for (auto &j : i.keys)
                {
                    if (j == query)
                    {
                        ans.push_back(i);
                        break;
                    }
                }
            }
        }
        if (num[0] == '4')
        {
            for (auto &i : v)
            {
                if (i.publisher == query)
                {
                    ans.push_back(i);
                }
            }
        }
        if (num[0] == '5')
        {
            for (auto &i : v)
            {
                if (i.year == query)
                {
                    ans.push_back(i);
                }
            }
        }
        if (ans.size() == 0)
        {
            cout << "Not Found" << endl;
        }
        else
        {
            for (auto &i : ans)
            {
                cout << i.id << endl;
            }
        }
    }
    return 0;
}