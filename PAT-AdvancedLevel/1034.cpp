#include <bits/stdc++.h>
using namespace std;
#define LOCAL
// 结点总数最大值
const int N = 2010;

int n, k;
// 并查集的祖先节点
vector<int> father(N);
// 每个人对应的通话时间
vector<int> times(N);
// 每个帮派的总人数
vector<int> num(N);
// 每个帮派的总通话时间
vector<int> totalTime(N);
// 每个帮派的头头
vector<int> head(N);
// 存储所有人
vector<string> names;
// 存储所有人对应的编号
unordered_map<string, int> um;

// 并查集
int find(int x)
{
    if (father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("1034in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    // 初始时让每个结点的祖先等于自己，表示离散 
    iota(father.begin(), father.end(), 0);
    // 初始时让每个帮派的头头等于自己，表示离散
    iota(head.begin(), head.end(), 0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        string name1, name2;
        int w;
        cin >> name1 >> name2 >> w;
        // 如果该人未出现过
        if (!um.count(name1))
        {
            // 存储他的名字以及对应编号
            um[name1] = um.size();
            // 将其加入所有人的集合
            names.push_back(name1);
        }
        if (!um.count(name2))
        {
            um[name2] = um.size();
            names.push_back(name2);
        }
        // 使通话两侧的人通话时间增加
        // 并使用um来索引人名对应的下标
        times[um[name1]] += w;
        times[um[name2]] += w;
        // 合并两个集合
        int u1 = find(um[name1]);
        int u2 = find(um[name2]);
        father[u1] = u2;
    }
    // 遍历每个人
    for (int i = 0; i < names.size(); ++i)
    {
        // 找到该人对应的祖先，也就是该人所在的帮派
        int root = find(i);
        // 使该帮派人数加一
        ++num[root];
        // 该帮派总时间加上该人的时间
        totalTime[root] += times[i];
        // 如果该人的通话时间大于该帮派目前头头的时间
        if (times[i] > times[head[root]])
        {
            // 使该人成为该帮派新头头
            head[root] = i;
        }
    }
    // 存储各帮派头头名和帮派人数
    vector<pair<string, int>> ans;
    // 遍历每个人
    for (int i = 0; i < names.size(); ++i)
    {
        // 如果满足帮派条件：
        // 1. 该人是帮派根节点
        // 2. 该帮派总人数大于2
        // 3. 该帮派总通话时间 > 给定阈值的2倍（因为在计算每个人的通话时间时，一条边上的两个点都加了改边的权值，因此将给定阈值也加倍）
        if (i == father[i] && num[i] > 2 && totalTime[i] > 2 * k)
        {
            // 成为帮派，加入答案
            // 帮派头头编号：head[i] 名字： names[head[i]]
            // 帮派人数：num[i]
            ans.push_back({names[head[i]], num[i]});
        }
    }
    // 排序；按字典序
    sort(ans.begin(), ans.end());
    // 输出帮派总数
    cout << ans.size() << endl;
    for (auto &i : ans)
    {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}