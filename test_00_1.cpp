/*任务描述
水仙花数是指一个m位自然数等于自身各个数位上数字的m次幂之和。例如：153是一个三位的水仙花数，1^3 + 5^3+3^3 = 153。
现在输入n个数字，请你帮帮小蓝鲸判断它们是不是水仙花数。

输入
第一行输入一个整数n，接下来n行，每行输入一个需要判断的整数，其范围属于[1, 1e9]。

输出
共n行，对于每个输入，输出它是否为水仙花数，如果是水仙花数，输出1，否则输出0。*/
#include <iostream>
using namespace std;

long f(int n)
{
    long count = 0;
    while (n > 0)
    {
        n = n / 10;
        count ++;
    }
    return count;
}

long g(long x, long m)
{
    long ans = 1;
    for (int i = 0; i < m; i++)
    {
        ans *= x;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    long x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int j = 0; j < n; j++)
    {
        long x_0 = x[j];
        long sum = 0;
        long count = f(x[j]);
        while (x[j] > 0)
        {
            long y = x[j] % 10;
            x[j] = x[j] / 10;
            sum += g(y, count);
        }
        if (sum == x_0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}