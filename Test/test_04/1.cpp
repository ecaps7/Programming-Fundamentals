/*任务描述
小花准备用正在学习的程序设计方法对一条基因序列 str（长度∈[2, 300]）进行转换。其转换过程是从左到右依次将 str 的每个字符自上而下分到 r（∈[2, 150]）行字符串中。
按小花的理解，如果转换后的 r 行字符串的长度不都相等，或者某行不是同一种字符，说明 str 不是串联重复基因序列，就输出 N。否则，就将转换后的 r 行字符串按从上到下的顺序输出。
请你用C/C++语言实现转换过程，以及结果的输出。

要求：

不得使用strlen之外的其他字符串处理库函数或string类库成员函数，不得使用vector或其他STL。
使用以下任一形式存储转换结果： 1）行数为150、列数为300的二维数组； 2）行数为 r、列数为300的二维动态数组。
输入格式（两行）
第一行，一个正整数（代表 r）
第二行，一个字符串（代表 str，不含空格）

输出格式（一行）
一个大写字母 N（代表 str 不是串联重复基因序列）
或者
r 行，每行一个字符串（代表转换后的 r 个字符串）

样例1
输入：
3
ATCATCATCATCATCATCATCATCATCATCATCATCATCATCATCATC
预期输出：
AAAAAAAAAAAAAAAA
TTTTTTTTTTTTTTTT
CCCCCCCCCCCCCCCC

样例2
输入：
4
ATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATCGATC 
预期输出：
N
解释：转换之后的第 4 行字符串与其他行长度不等
AAAAAAAAAAAA
TTTTTTTTTTTT
CCCCCCCCCCCC
GGGGGGGGGGG

样例3
输入：
2
AGAGAGAGAGAGAGAGAGAGAGAGAGAGAGAGAGAGAX
预期输出：
N
解释：转换之后的第 2 行字符串不是同一种字符
AAAAAAAAAAAAAAAAAAA
GGGGGGGGGGGGGGGGGGX*/
#include <iostream>
#include <cstring>
using namespace std;

char ans[150][300];

int main()
{
    int r;
    cin >> r;
    char str[301];
    cin >> str;
    int length = strlen(str);
    if (length % r != 0)
    {
        cout << "N" << endl;
        return 0;
    }
    int times = length / r;
    for (int i = 0; i < times; i++)
    {
        for (int j = 0; j < r; j++)
        {
            ans[j][i] = str[r * i + j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < times - 1; j++)
        {
            if (ans[i][j] != ans[i][j + 1])
            {
                cout << "N" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < times; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}