/*8 7 8 7
#######
#_____#
#_###_#
#_#_#_#
#_#_#_#
#_#_#_#
#___#_#
#####_#*/
#include <iostream>
using namespace std;

int main()
{
    int n, m;//n 为行，m 为列
    int x, y;//x 为行，y 为列
    cin >> n >> m >> x >> y;
    char vis[n + 1][m + 1];
    int times = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> vis[i][j];
            if (vis[i][j] == '#')
            {
                times++;
            }
        }
    }
    cout << times << endl;
    cout << x << " " << y << endl;
    vis[x][y] = '_';
    int time = 0;
    while(true)
    {
        if (x != n)
        {
            if (vis[x + 1][y] == '#')
            {
                cout << x + 1 << " " << y << endl;
                vis[x + 1][y] = '_';
                x = x + 1;
                time++;
                continue;
            }
        }
        if(x != 1)
        {
            if (vis[x - 1][y] == '#')
            {
                cout << x - 1 << " " << y << endl;
                vis[x - 1][y] = '_';
                x = x - 1;
                time++;
                continue;
            }
        }
        if (y != m)
        {
            if (vis[x][y + 1] == '#')
            {
                cout << x << " " << y + 1 << endl;
                vis[x][y + 1] = '_';
                y = y + 1;
                time++;
                continue;
            }
        }
        if (y != 0)
        {
            if (vis[x][y - 1] == '#')
            {
                cout << x << " " << y - 1 << endl;
                vis[x][y - 1] = '_';
                y = y - 1;
                time++;
                continue;
            }
        }
        if (time == 0)
        {
            break;
        }
        time = 0;
    }
    return 0;
}