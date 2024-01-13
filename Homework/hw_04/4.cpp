/*任务描述
已知2000年1月1日是星期六，请问X年Y月Z日是星期几？
输入
共1行，三个整数X，Y，Z。
X，Y，Z 保证能够组成合法日期 (1 <= X <= 9999)   
输出
共1行，一个整数代表星期几。
（星期日:7，星期一：1，...，星期六：6）
注：闰年是1)能被400整除 2)能被4整除但不能被100整除的年份*/
#include <iostream>
using namespace std;

bool is_leapyear(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int days = 0;
    int days_0 = 0;//计算当年到那一天为止有多少天
    int days_1 = 0;//计算间隔整年的天数
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month_1[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (x >= 2000)
    {
        for (int i = 2000; i < x; i++)
        {
            if (is_leapyear(i))
            {
                days_1 += 366;
            }
            else
            {
                days_1 += 365;
            }
        }//计算间隔整年的天数
        if (is_leapyear(x) && y >= 3)
        {
            for (int i = 0; i < y - 1; i++)
            {
                days_0 += month_1[i];
            }
        }
        else
        {
            for (int i = 0; i < y - 1; i++)
            {
                days_0 += month[i];
            }
        }//计算当年到那一个月为止有多少天
        days = days_0 + days_1 + z - 1;
        int ans = (6 + days % 7) % 7;
        if (ans == 0)
        {
            cout << 7;
        }
        else
        {
            cout << ans;
        }
    }
    else
    {
        for (int i = x + 1; i < 2000; i++)
        {
            if (is_leapyear(i))
            {
                days_1 += 366;
            }
            else
            {
                days_1 += 365;
            }
        }//计算间隔整年的天数
        if (is_leapyear(x))
        {
            for (int i = 11; i > y - 1; i--)
            {
                days_0 += month_1[i];
            }
            days = days_0 + days_1 + month_1[y - 1] - z + 1;
        }
        else
        {
            for (int i = 11; i > y - 1; i--)
            {
                days_0 += month[i];
            }
            days = days_0 + days_1 + month[y - 1] - z + 1;
        }
        int ans = 6 - days % 7;
        if (ans == 0)
        {
            cout << 7;
        }
        else
        {
            cout << ans;
        }
    }
    return 0;
}