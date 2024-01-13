/*题目：输入一个正整数m，重复进行以下操作：

1.如果 m < 10，输出 m ，结束程序；
2. 否则，令 m 等于 m 中各位非零数字的乘积。

测试用例
输入：12045
输出：4
*/
#include <iostream>
using namespace std;

int len(int N)
{
    int ans_0 = 1;
    while (N >= 10)
    {
        N = N / 10;
        ans_0 ++;
    }
    return ans_0;
}

int power(int m)
{
    int ans_1 = 1;
    for (int i = 0; i < m; i++)
    {
        ans_1 *= 10;
    }
    return ans_1;
}

int main()
{
    int n;
    cin >> n;
    while (true)
    {
        if (n < 10)
    {
        cout << n;
        break;
    }
    else
    {
        int ans = 1;
        for (int i = 0; i <= len(n); i++)
        {
            if ((n / power(i)) % 10 != 0)
            {
                ans *= (n / power(i)) % 10;
            }
        }
        n = ans;
    }
    }
    return 0;
}