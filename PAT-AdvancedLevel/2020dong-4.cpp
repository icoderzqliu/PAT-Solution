#include <bits/stdc++.h>
using namespace std;
//#define LOCAL

int n, m, k;

unordered_map<int, int> reactant;
vector<int> product;
unordered_map<int, set<vector<int>>> equation;

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
    for (int i = 0; i < n; ++i)
    {
        int r;
        cin >> r;
        reactant[r] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int p;
        cin >> p;
        product.push_back(p);
    }
    cin >> k;
    getchar();
    for (int i = 0; i < k; ++i)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> v;
        int pro;
        string t;
        vector<string> vs;
        while (ss >> t)
        {
            vs.push_back(t);
        }
        for (int i = 0; i < vs.size() - 2; ++i)
        {
            if (vs[i][0] != '+')
                v.push_back(stoi(vs[i]));
        }
        pro = stoi(vs.back());
        equation[pro].insert(v);
    }
    for (int i = 0; i < product.size(); ++i)
    {
        // if (reactant[product[i]] == 1)
        // {
        //     reactant[product[i]]--;
        //     printf("%02d -> %02d", product[i], product[i]);
        //     if (i != product.size())
        //         printf("\n");
        //     continue;
        // }
        set<vector<int>> svi = equation[product[i]];
        vector<int> ans;

        if (reactant[product[i]] == 1)
        {
            svi.insert({product[i]});
        }
        
        for (auto vi : svi)
        {
            bool flag = true;
            for (auto i : vi)
            {
                if (reactant[i] == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans = vi;
                for (auto i : vi)
                {
                    reactant[i]--;
                }
                break;
            }
        }
        for (int j = 0; j < ans.size(); ++j)
        {
            printf("%02d", ans[j]);
            if (j == ans.size() - 1)
            {
                printf(" -> ");
            }
            else
            {
                printf(" + ");
            }
        }
        printf("%02d", product[i]);
        if (i != product.size() - 1)
            printf("\n");
    }
    return 0;
}