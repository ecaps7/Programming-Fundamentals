/*任务描述
对于不小于10的整数，我们把它称为“等差数”当且仅当这个数字的十进制表示中不含0，而且任意两个相邻数位前一位减去后一位的差是相同的且不为0。注意，不含0且两个数位不相同的的每个两位数都是等差数。例如1357、642、567、26、987654321都是等差数，而124、532、646、30、22、666都不是等差数。
我们把所有等差数分成多个类别，类别号是一个整数，如果x的十进制写法中首位和末位的和是p，则将x归为第p类，如1357、17、7531、26、246、23456类别均为8。
给定数字x，你需要判断x是否是等差数，如果是则输出x的类别，否则输出-1。
输入
我们有n个整数要判断，输入第一行有一个整数n，接下来有n行，每行有一个待判断的非负整数x。(1≤n≤6000,0≤x≤2∗10^9)
输出
输出n行，每行一个整数，代表每个整数的判断结果。*/
#include <iostream>
using namespace std;


int judge(long n)
{
    if(n < 10)
    {
        return -1;
    }
    else if (n >= 10 && n < 100)
    {
        if (n % 10 == 0 || n % 11 == 0)
        {
            return -1;
        }
        return (n / 10 + n % 10);
    }
    else 
    {
        int times = 0;
        int x[12];
        while (n > 0)
        {
            x[times] = n % 10;
            n = n / 10;
            times++;
        }
        for (int j = 0; j < times - 1; j++)
        {
            int difference = x[1] - x[0];
            if (x[j + 1] - x[j] != difference || difference ==0)
            {
                return -1;
            }
        }
        for (int i = 0; i < times; i++)
        {
            if (x[i] == 0)
            {
                return -1;
            }
        }
        return (x[0] + x[times - 1]);
    }
}

int main()
{
    int nums[6001];
    int n;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        cin >> nums[k];
    }
    for (int i = 0; i < n; i++)
    {
        cout << judge(nums[i]) << endl;
    }
    return 0;
}