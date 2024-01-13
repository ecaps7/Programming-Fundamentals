#include <iostream>
#include <vector>
using namespace std;

struct Water
{
    int x;
    int y;
    Water(int m, int n)
    {
        x = m;
        y = n;
    }
};

void func(vector<vector<int>>& map, int m, int n)
{
    vector<Water> water;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1)
            {
                Water temp(i, j);
                water.push_back(temp);
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!water.empty())
    {
        int length = water.size();
        int w_x = water[length - 1].x;
        int w_y = water[length - 1].y;
        water.pop_back();

        for (int i = 0; i < 4; i++)
        {
            int nx = w_x + dx[i];
            int ny = w_y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[nx][ny] == 0)
            {
                map[nx][ny] = 1;
                Water tmp(nx, ny);
                water.push_back(tmp);
            }
        }
    }
}

int main()
{
    int m;
    int n;
    cin >> m >> n;
    vector<vector<int>> map(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    func(map, m, n);

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