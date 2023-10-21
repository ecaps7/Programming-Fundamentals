/*任务描述
你正在召唤师峡谷进行探索，突然遇到了一只野生小提莫。提莫的血量为m，你可以对其进行物理攻击（伤害为1）和法术攻击（伤害为2），请问有多少种击杀提莫的方式（血量少于1视为击杀）。
输入
1行，1个整数m。(1≤m≤50)
输出
1行，一个整数代表结果。*/
//此题是一个斐波那契数列的实例
#include <iostream>
using namespace std;


int main()
{
    int m;
    cin >> m;
    long long count[51];
    count[0] = 1;
    count[1] = 1;
    count[2] = 2;
    for (int i = 3; i <= 50; i++)
    {
        count[i] = count[i - 1] + count[i - 2];
    }
    long long ans = count[m] + count[m - 1];
    cout << ans;
    return 0;
}