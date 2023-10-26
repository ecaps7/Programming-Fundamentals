/*任务描述
编写一段程序实现对一个n位数x，交换其的第k位和第n+1-k位(从左到右计算位数，即第1位为数字最高位)，返回其交换后的数值。例如12345，交换第1位和第5位为52341；2468，交换第2位和第3位为2648。（保证输入的n位数x不含有0）

输入
一行三个数字分别为n、x、k，
1<=n，k<=9,1<=x<=999 999 999。

输出
返回其交换后的数值

样例
样例1
输入
5 12345 1

输出
52341

样例2
输入
7 1367789 6

输出
1867739
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long x;
    int n, k;//n 为数字的倍数，k 为交换的一个位数
    cin >> n >> x >> k;
    string num = to_string(x);
    char temp = num[k - 1];
    num[k - 1] = num[n - k];
    num[n - k] = temp;
    for (int i = 0; i < n; i++)
    {
        cout << num[i];
    }
    return 0;
}