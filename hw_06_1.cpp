/*任务描述
现有1元、2元和5元的货币（数量不限），请计算购买价值为n元的物品共有多少种支付方式（要求输出每一种支付方式）。（n为整数且 0 < n < 100）
输入
物品的价值 n
输出：
第一行：所有支付方式个数 m。
后面每行输出一种方式，每种方式按照1元，2元和5元的顺序输出，中间用空格隔开。所有行按1元个数递减排序，若1元个数相同则按2元个数递减排序。*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long count = 0;
    for (int i = n / 5 + 1; i >= 0; i--)
    {
        for (int j = (n - 5 * i) / 2 + 1; j >= 0; j--)
        {
            if ((n - 5 * i - 2 * j) >= 0)
            {
                count += 1;
            }
        }
    }
    cout << count << endl;
    for (int i = n; i >= 0; i--)
    {
        for (int j = (n - i) / 2 + 1; j >= 0; j--)
        {
            for (int k = (n - i - 2 * j) / 5 + 1; k >= 0; k--)
            {
                if (i + 2 * j + 5 * k == n)
                {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
}