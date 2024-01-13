/*3 4
N J U N
J A J B
U J N C*/
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char words[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> words[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            if ((words[i][j] == 'N' && words[i][j+1] == 'J' && words[i][j+2] == 'U')||(words[i][j] == 'U' && words[i][j+1] == 'J' && words[i][j+2] == 'N'))
            {
                count++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 2; j++)
        {
            if ((words[j][i] == 'N'&&words[j+1][i] == 'J'&&words[j+2][i] == 'U')||(words[j][i] == 'U'&&words[j+1][i] == 'J'&&words[j+2][i] == 'N'))
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}