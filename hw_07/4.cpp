/*任务描述
我们称一个数X为好数，如果它的每位数字逐个地被旋转180度后，我们仍可以得到一个有效的，且和X不同的数。
具体数字旋转规则：
如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的；
数字0、1和8被旋转后仍然是它们自己；
数字2和5可以互相旋转成对方，数字6和9同理。
(比如118每位数字旋转后仍为118，旋转前后数字相同，那么它不是好数；205每位数字旋转后得到502，旋转前后数字不同，那么它是好数；31每位数字旋转后无法得到有效的数字所以它不是好数）

现在我们有一个正整数N，计算从1到N(包含1和N)中好数的和是多少？

输入
一个正整数N，1<=N<=100000

输出
从1到N中好数的和

样例1
输入
50
输出
305
解释：
从1到50中包含的好数有2、5、6、9、12、15、16、19、20、21、22、25、26、28、29、50，其总和为305。*/
#include <iostream>
#include <string>
using namespace std;

int magic(int n)
{
    if (n == 0 || n == 1 || n == 8)
    {
        return n;
    }
    else if (n == 2)
    {
        return 5;
    }
    else if (n == 5)
    {
        return 2;
    }
    else if (n == 6)
    {
        return 9;
    }
    else if (n == 9)
    {
        return 6;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        string num = to_string(i);
        int len = num.size();
        string num_0 = to_string(i);
        int result = 0;
        for (int j = 0; j < len; j++)
        {
            result = magic(num[j] - '0');
            if (magic(num[j] - '0') == -1)
            {
                break;
            }
            num[j] = '0' + magic(num[j] - '0');
        }
        if (result == -1)
        {
            continue;
        }
        if (num_0 != num)
        {
            sum += i;
        }
    }
    cout << sum;
    return 0;
}