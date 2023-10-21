/*任务描述
任何一个正整数都可以用2的幂次方表示。例如：137=2^7+2^3+2^0。同时约定方次用括号来表示，即 a^b可表示为 a(b)。由此可知，137 可表示为：2(7)+2(3)+2(0)。进一步：7=2(2)+2+2(0)（(2^1) 用 2 表示），3=2+2^0。所以最后 137 可表示为：2(2(2)+2+2(0))+2(2+2(0))+2(0)

输入                                          样例输入
一个正整数n (n <= 20000)                       1315 = 2^10 + 2^8 + 2^5 + 2^1 + 2^0 = 2(10) + 2(8) + 2(5) + 2 + 2(0)     0101 0010 0011

输出                                          样例输出
符合约定的2的表示结果(在表示中不能有空格)        2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string to_binary(int n)
{
    string str = "";
    while (n > 0)
    {
        str += to_string(n % 2);
        n = n / 2;
    }
    reverse(str.begin(), str.end());
    return str;
}

// void print_ans(string str)
// {
//     if (str == "0")
//     {
//         return;
//     }
//     if (str == "1")
//     {
//         cout << "1";
//         return;
//     }
//     if (str == "10")
//     {
//         cout << "2";
//         return;
//     }
//     if (str == "11")
//     {
//         cout << "2+2(0)";
//         return;
//     }
//     for (int i = 0; i < str.length(); i++)
//     {
//         if (str[i] == '0')
//         {
//             continue;
//         }
//         else
//         {
//             if (i == 0)
//             {
//                 cout << "2(";
//                 print_ans(to_binary(str.length() - i - 1));
//                 cout << ")";
//                 continue;
//             }
//             if (i == str.length() - 1)
//             {
//                 cout << "+2(0)";
//                 continue;
//             }
//             else if (i == str.length() - 2)
//             {
//                 cout << "+2";
//                 continue;
//             }
//             else
//             {
//                 cout << "+2(";
//                 print_ans(to_binary(str.length() - i - 1));
//                 cout << ")";
//             }
//         }
        
//     }
// }这个函数有一点点问题

void print_ans(string str, int k)
{
    if (k == str.length())
    {
        return;
    } 
    char num_k = str[k];
    if (num_k == '0')
    {
        print_ans(str, k + 1);
    }
    else
    {
        if (k != 0)
        {
            cout << "+";
        }
        if (k == str.length() - 1)
        {
            cout << "2(0)";
        }
        else if (k == str.length() - 2)
        {
            cout << "2";
        }
        else
        {
            cout << "2(";
            print_ans(to_binary(str.length()- k - 1),0);//0 -- length-1; 1 -- 
            cout << ")";
        }
        print_ans(str, k + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    print_ans(to_binary(n), 0);
    return 0;
}