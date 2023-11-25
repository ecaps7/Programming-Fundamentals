//一种效率较低的解法
#include <iostream>

const int INF = 0x3f3f3f3f;

int n, m;
int xs, ys, xt, yt;

bool vis[110][110];
bool mp[110][110];

int ansx[10010], ansy[10010];

int ans = INF;

//一个比较经典的写法

//vx和vy数组代表了四个方向
int vx[4] = {0, 0, 1, -1};
int vy[4] = {1, -1, 0, 0};

//模拟寻路，cnt代表走了多少步
void dfs(int x, int y, int cnt){

    //这个点来过了
    vis[x][y] = true;
    ansx[cnt] = x;
    ansy[cnt] = y;

    if (x == xt && y == yt) {
        int res = 0;
        for (int i = 3; i <= cnt; i++) {
            if (ansx[i] - ansx[i - 1] != ansx[i - 1] - ansx[i - 2] || ansy[i] - ansy[i - 1] != ansy[i - 1] - ansy[i - 2]) {
                res++;
            }
        }
        ans = std::min(ans, res);
    } else {

        //四个方向
        for (int i = 0; i < 4; i++) {
            int nx = x + vx[i];
            int ny = y + vy[i];

            //如果这个点是_或者已经走过了，那么就不走了
            if (!mp[nx][ny] || vis[nx][ny]) {
                continue;
            } else {
                dfs(nx, ny, cnt + 1);
            }
        }
    }
    vis[x][y] = false;//把走过的所有轨迹都擦除，换一条路重新走
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m >> xs >> ys >> xt >> yt;
    n++, m++;

    //初始化，将将矩阵外面一圈都变成_，防止越界等问题
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <m; j++) {
            char input = '_';
            std::cin >> input;
            mp[i][j] = (input == '#');
        }
    }
    dfs(xs, ys, 1);
    printf("%d\n", ans);
    return 0;
}