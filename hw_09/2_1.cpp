#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
char* GetStrings(int n)
{
    char* str_list = new char(n);
    for (int i = 0; i < n; i++)
    {
        cin >> (str_list + i);
    }
    return str_list;
}

void Func(char* str_list, int n)
{
    int judge = 1;
    if (n == 1)
    {
        cout << *(str_list) << endl;
        return;
    }
    char* str = new char(n);
    for (int k = 1; k <= n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            *(str + (k + i) % n) = *(str_list + i);
        }
        for (int j = 0; j < n; j++)
        {
            if (*(str + j) != *(str + n - 1 - j))//?
            {
                judge = 0;
                break;
            }
        }
    }
}