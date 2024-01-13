#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define me(a, x) memset(a, x, sizeof(a))
const double pi = acos(1.0);
const double e = exp(-1.0);
const int MAXN = 200010;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

bool vis[100][100];
char mp[100][100];

int ansx[10000], ansy[10000];

// 一个比较经典的写法

// vx和vy数组代表了四个方向
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, 1, -1};

// 模拟寻路，cnt代表走了多少步
void dfs(int x, int y, int cnt)
{
    // 这个点来过了
    vis[x][y] = true;
    ansx[cnt] = x;
    ansy[cnt] = y;
    // #数量
    int q = 0;
    // 四个方向
    for (int i = 0; i < 4; i++)
    {
        int nx = x + vx[i];
        int ny = y + vy[i];
        // 如果这个点是_或者已经走过了，那么就不走了
        if (mp[nx][ny] == '_' || vis[nx][ny])
            continue;
        else
        {
            q++;
            dfs(nx, ny, cnt + 1);
        }
    }
    // 如果这个点四周都走过了，那么代表走到尾了
    if (q == 0)
    {
        cout << cnt << "\n";
        for (int i = 1; i <= cnt; i++)
        {
            cout << ansx[i] << " " << ansy[i] << "\n";
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int x0, y0;
    cin >> x0 >> y0;
    // 初始化，将将矩阵外面一圈都变成_，防止越界等问题
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            if (i == 0 || j == 0 || (i == n + 1) || (j == m + 1))
            {
                mp[i][j] = '_';
                continue;
            }
            cin >> mp[i][j];
        }
    }

    dfs(x0, y0, 1);
    return 0;
}