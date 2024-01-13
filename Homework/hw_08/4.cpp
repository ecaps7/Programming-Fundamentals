#include <iostream>
#include <cmath>
using namespace std;

//row为行, col为列
void draw(char a[][64], int n, int row, int col)
{
    if (n == 1)
    {
        a[row][col] = '*';
        return;
    }
    int width_1 = pow(2, n - 2);
    draw(a, n - 1, row, col);
    draw(a, n - 1, row, col + width_1);
    draw(a, n - 1, row + width_1, col);
}

int main()
{
    char a[64][64];
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            a[i][j] = ' ';
        }
    }
    int n;
    cin >> n;
    int width = pow(2, n - 1);
    draw(a, n, 0, 0);
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width - i; j++)
        {
            if (j < width - i - 1)
            {
                cout << a[i][j] << " ";
            }
            else
            {
                cout << a[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}