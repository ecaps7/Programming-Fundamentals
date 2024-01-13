/*求n个分数的和，结果需要化简。特别地，如果结果为0，输出0 1。
输入:两行
第一行输入一个整数n（1<n<20），第二行n个整数表示分子，第三行n个整数表示分母。
分子分母均为非负数且小于1e4。
保证分母的最小公倍数在int范围之内。
输出：计算结果在一行内用空格隔开，分子在前分母在后。*/
#include <iostream>
using namespace std;

int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}

int lcm(int m, int n)
{
    return m * n / gcd(m, n);
}

int main()
{
    int n = 0;
    cin >> n;
    int numerator[n];//分子
    int denominator[n];//分母
    int lcm_den = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> numerator[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> denominator[j];
        lcm_den = lcm(lcm_den, denominator[j]);
    }
    
    int ans_den = lcm_den;
    int ans_num = 0;
    for (int k = 0; k < n; k++)
    {
        ans_num += numerator[k] * lcm_den / denominator[k];
    }
    if (ans_den == 0)
    {
        cout << 0 << " " << 1;
    }
    else
    {
        int ans_0 = gcd(ans_den, ans_num);
        ans_den = ans_den / ans_0;
        ans_num = ans_num / ans_0;
        cout << ans_num << " " << ans_den;
    }
    return 0;
}