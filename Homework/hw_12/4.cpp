#include <iostream>
#include <cstring>
using namespace std;

bool Judge(char str[], int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[100];
    cin >> str;
    int length = strlen(str);
    while (length % 2 == 0 && Judge(str, length))
    {
        length /= 2;
    }
    cout << length << endl;
    return 0;
}