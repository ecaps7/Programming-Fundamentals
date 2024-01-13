/*任务描述
同学们喜欢玩“算24”游戏，但是觉得四则运算太难了，助教帮他们降低了难度，只使用两则运算（+和-），并改成“算k”游戏：给定n个非负整数和一个目标k，固定这n个数的顺序，只使用加减法，计算有多少种方式可以得到k，并输出所有的方式。

输入
2行，第1行两个整数分别代表数组长度n和目标k,第2行n个数，代表数组元素（1≤n≤10, 0≤数组元素≤1000）。

输出
第1行整数表示结果数，接下来每行一个结果，按+号优先排列。

样例
输入
4 3
1 1 1 2
输出
3
+1+1-1+2
+1-1+1+2
-1+1+1+2*/

#include <iostream>
#include <vector>
using namespace std;
int nums[1000]{};
int result = 0;
int count = 0;

void pri_ans(int n, vector<int>& sign)
{
    for (int i = 0; i < n; i++)
    {
        if (sign[i] == 1)
        {
            cout << "+" << nums[i];
        }
        else
        {
            cout << "-" << nums[i];
        }
    }
    cout << endl;
}

void cal_0(int i, vector<int>& sign, int n, int k)
{
    if (i == n && result == k)
    {
        count++;
        // pri_ans(n, sign);
        return;
    }

    else if (i == n)
    {
        return;
    }

    int x = 1;
    sign.push_back(x);
    result = result + nums[i];
    cal_0(i + 1, sign, n, k);
    result = result - nums[i];
    sign.pop_back();

    int y = 0;
    sign.push_back(y);
    result = result - nums[i];
    cal_0(i + 1, sign, n, k);
    result = result + nums[i];
    sign.pop_back();
}

void cal(int i, vector<int>& sign, int n, int k)
{
    if (i == n && result == k)
    {
        pri_ans(n, sign);
        return;
    }

    else if (i == n)
    {
        return;
    }

    int x = 1;
    sign.push_back(x);
    result = result + nums[i];
    cal(i + 1, sign, n, k);
    result = result - nums[i];
    sign.pop_back();

    int y = 0;
    sign.push_back(y);
    result = result - nums[i];
    cal(i + 1, sign, n, k);
    result = result + nums[i];
    sign.pop_back();
}

int main()
{
    int n;
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> sign;
    cal_0(0, sign, n, k);
    cout << count << endl;
    cal(0, sign, n, k);
}