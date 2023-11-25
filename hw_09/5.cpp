/*考察知识点
递归，数组，字符串，循环与分支

任务描述
对于由小写拉丁字母组成的非空字符串s，如果s满足以下条件之一，我们称字符串s为k级：

s的长度为1，只包含一个字符k；
s的长度为2，包含字符k和k+1；
s的长度大于2且为2的整数次幂，对于其前半部分和后半部分的两个子串，其中一个全由字符k组成，另一个为(k+1)级字符串或(k-1)级字符串。
其中，对于字符k，我们称字符k+1为k的下一个字符，k-1为k的上一个字符.例如:字符c+1为d，c-1为b。请注意字符a-1和z+1是不存在的。

例如b,bc,cb,bbcd,cdbb,bbbbccde,bbbbdecc,bbab,bbbbaabc,aabcbbbb都是b级字符串。bbce,bbaa,bbac,aabb,bbbbccdc不属于任何一个等级的字符串。

现在给你提出了T个字符串，你需要给出每个字符串的等级，如果该字符串不属于任何一个等级，输出字符0.

输入
我们有T个字符串要判断，输入第一行有一个整数T，接下来T行，每行一个待判断的非空字符串。(1≤T≤3000)， 每个字符串长度不大于128，且长度为2的非负整数次幂。

输出
输出T行，每行一个字符，代表每个字符串的判断结果。

样例
样例1
输入 1 ab

输出 a

样例2
输入 9 b bc bbcd bbbbccde aabcbbbb ccde bbce bbaa bbbbccdc

输出
b b b b b c 0 0 0*/
#include <bits/stdc++.h>
using namespace std;

char same(string str)
{
    for (char ch : str)
    {
        if (ch != str[0])
        {
            return '0';
        }
    }
    return str[0];
}

bool judge_0(int n)
{
    while (n >= 2)
    {
        if (n % 2 != 0)
        {
            return false;
        }
        else
        {
            n = n / 2;
        }
    }
    return true;
}

char judge(string s)
{
    int length = s.size();
    if (length == 1)
    {
        return s[0];
    }
    if (length == 2 && fabs(s[0] - s[1]) == 1)
    {
        return (s[0] < s[1] ? s[0] : s[1]);
    }
    if (!judge_0(length))
    {
        return '0';
    }
    else
    {
        string str_1{}, str_2{};
        for (int i = 0; i < length / 2; i++)
        {
            str_1 += s[i];
            str_2 += s[i + length / 2];
        }
        char result_1 = judge(str_1);
        char result_2 = judge(str_2);
        if (same(str_1) != '0' && fabs(same(str_1) - result_2) == 1)
        {
            return same(str_1);
        }
        else if (same(str_2) != '0' && fabs(same(str_2) - result_1) == 1)
        {
            return same(str_2);
        }
        else
        {
            return '0';
        }
    }
}

int main()
{
    int t;
    cin >> t;
    string *str = new string[t];
    for (int i = 0; i < t; i++)
    {
        cin >> str[i];
    }
    for (int i = 0; i < t; i++)
    {
        cout << judge(str[i]) << endl;
    }
    delete[] str;
    return 0;
}