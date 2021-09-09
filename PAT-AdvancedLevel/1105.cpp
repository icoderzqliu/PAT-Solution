#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
const int N = 10010;

int n;
int a[N];
int matrix[110][110];
int row, col;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

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
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (col = sqrt(n); n % col; col--)
        ;
    row = n / col;
    int d = 0, x = 0, y = 0;
    for (int i = 1; i <= n; ++i)
    {
        matrix[x][y] = a[i];
        int nx = x + dir[d][0], ny = y + dir[d][1];
        if (nx >= 0 && nx < row && ny >= 0 && ny < col && matrix[nx][ny] == 0)
        {
            x = nx, y = ny;
        }
        else
        {
            d = (d + 1) % 4;
            x = x + dir[d][0];
            y = y + dir[d][1];
        }
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cout << matrix[i][j] << (j == col - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}