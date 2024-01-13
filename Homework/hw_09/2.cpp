/*任务描述
古代中国追求对称美，对字符串要求亦是如此。给定一个长度为N的字符串，你可以认为他们是首尾相连的，如果经过平移，这个字符串能否形成对称的效果？如果可以，请输出对称的字符串，否则输出False。如果对称的字符串有多种可能，那么只输出取向右平移次数最少的字符串。要求：用指针来进行处理。
输入
先输入一个正整数N，表示接下来会输入N个字符，每个字符用空格隔开。
输出
经过平移后对称的字符串或者False

样例1
输入：
3
b b a
输出：
b a b
解析：bba向右平移两次得到bab，是对称的

样例2
输入：
4
a b c c
输出：
False*/
#include <bits/stdc++.h>
using namespace std;

char* GetStrings(int n)
{
    char* str_list = new char[2 * n];
    for (int i = 0; i < n; i++)
    {
        cin >> *(str_list + i);
        *(str_list + i + n) = *(str_list + i);
    }
    return str_list;
}

void Func(char* str_list, int n)
{
    if (n == 1)
    {
        cout << *(str_list) << endl;
        return;
    }
    int times_fail = 0;
    bool judge = true;
    for (int i = 0; i < n - 1; i++)
    {
        // for (int j = i; j < i + n; j++)
        // {
        //     if (*(str_list + j) != *(str_list + n - 1  + 2 * i- j))
        //     {
        //         judge = false;
        //         times_fail++;
        //         break;
        //     }
        // }
        int j = n - i;
        while (j <= 3 * n - 1  - 2 * i- j)
        {
            if (*(str_list + j) != *(str_list + 3 * n - 1  - 2 * i- j))
            {
                judge = false;
                times_fail++;
                break;
            }
            j++;
        }
        if (judge == true)
        {
            for (int k = n - i; k < 2 * n - i; k++)
            {
                if (k != 2 * n - i - 1)
                {
                    cout << *(str_list + k) << " ";
                }
                else
                {
                    cout << *(str_list + k) << endl;
                }
            }
            delete[] str_list;
            return;
        }
        judge = true;
    }
    cout << "False" << endl;
    delete[] str_list;
}

int main()
{
    int n;
    cin >> n;
    Func(GetStrings(n), n);
    return 0;
}