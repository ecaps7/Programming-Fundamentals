/*
4 4
0 2 2 2
0 2 0 2
0 2 2 2
0 0 0 1*/
#include <iostream>
using namespace std;
int map[50][50]{};
bool visited[50][50]{false};

void find(int map[][50], int m, int n, int x, int y)
{
    if (x < 0 || x >= m || y < 0 || y >= n || map[x][y] == 2 || (visited[x][y] == true && map[x][y] == 1))
    {
        return;
    }
    map[x][y] = 1;
    visited[x][y] = true;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        find(map, m, n, nx, ny);
    }
}

int main()
{
    int m;
    int n;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1)
            {
                find(map, m, n, i, j);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
            {
                cout << map[i][j] << " ";
            }
            else
            {
                cout << map[i][j] << endl;
            }
        }
    }
    return 0;
}