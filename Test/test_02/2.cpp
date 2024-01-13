#include <iostream>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int b[k][k];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> b[i][j];
        }
    }
    int ans[m - k + 1][n - k + 1]{};
    for (int i = 0; i < m - k + 1; i++)
    {
        for (int j = 0; j < n - k + 1; j++)
        {
            for (int x = 0; x < k; x++)
            {
                for (int y = 0; y < k; y++)
                {
                    ans[i][j] += b[x][y] * a[i + x][j + y];
                }
            }
        }
    }
    for (int i = 0; i < m - k + 1; i++)
    {
        for (int j = 0; j < n - k + 1; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}