/*丑数是只包含质因数2,3,5的正整数，请判断一个给定的正整数 n 是否为丑数，是输出 Yes，否输出 No*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n % 2 == 0)
    {
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        n = n / 3;
    }
    while (n % 5 == 0)
    {
        n = n / 5;
    }
    if (n == 1)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}