//01-BFS
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <deque>

#define _N 1010
#define _INF 0x3f3f3f3f

struct State {
    int x, y, dir;
    State() {
        x = y = dir = 0;
    }
    State(int a, int b, int c) {
        x = a, y = b, dir = c;
    }
};

int n, m, xs, ys, xt, yt;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool map[_N][_N];

bool vis[_N][_N][4];
int cost[_N][_N][4];

std::deque<State> dq;

int ans = _INF;

int main() {
    memset(cost, 0x3f, sizeof(cost));
    scanf("%d%d%d%d%d%d", &n, &m, &xs, &ys, &xt, &yt);
    for (int i = 1; i <= n; i++) {
        char line[_N];
        scanf("%s", line + 1);
        for (int j = 1; j <= m; j++) {
            map[i][j] = (line[j] == '#');
        }
    }
    memset(cost[xs][ys], 0x00, sizeof(cost[xs][ys]));
    for (int k = 0; k < 4; k++) {
        dq.push_back(State(xs, ys, k));
    }
    while (!dq.empty()) {
        State top = dq.front();
        dq.pop_front();
        int x = top.x, y = top.y, dir = top.dir;
        if (!vis[x][y][dir]) {
            vis[x][y][dir] = true;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (1 <= nx && nx <= n && 1 <= ny && ny <= m && map[nx][ny] && !vis[nx][ny][dir]) {
                    if (dir == k) {
                        cost[nx][ny][k] = std::min(cost[nx][ny][k], cost[x][y][dir]);
                        dq.push_front(State(nx, ny, k));
                    } else {
                        cost[nx][ny][k] = std::min(cost[nx][ny][k], cost[x][y][dir] + 1);
                        dq.push_back(State(nx, ny, k));
                    }
                }
            }
        }
    }
    for (int k = 0; k < 4; k++) {
        ans = std::min(ans, cost[xt][yt][k]);
    }
    printf("%d\n", ans);
    return 0;
}