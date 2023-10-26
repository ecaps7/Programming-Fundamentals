/*矩阵乘法*/
#include <iostream>
using namespace std;

int main()
{
    int m, n, p;
    cin >> m >> n >> p;
    int matrix_1[m][n];
    int matrix_2[n][p];
    int result[m][p];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix_1[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> matrix_2[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                result[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            if (j == p - 1)
            {
                cout << result[i][j];
            }
            else
            {
                cout << result[i][j] << " ";
            }
        }
        if (i != m - 1)
        {
            cout << endl;
        }
    }
    return 0;
}