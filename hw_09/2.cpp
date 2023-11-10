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
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
//ToDo
char* GetStrings(int n)
{
    char* str_list = (char*)malloc((n) * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        std::cin >> (str_list + i);
    }
    return str_list;
}
//ToDo
//Attention!! str_list[i] is forbidden!!
void Func(char* str_list, int n)
{
    int length = n;
    if (n == 1)
    {
        std::cout << *(str_list);
        return;
    }
    char* str_1 = (char*)malloc((length) * sizeof(char));
    int judge = 1;
    for (int k = 1; k <= length; k++)
    {
        for(int i = 0; i < length; i++)
        {
            *(str_1 + (k + i) % length) = *(str_list + i);
        }
        for (int j = 0; j < length; j++)
        {
            if (*(str_1 + j) != *(str_1 + length - 1 - j))//?
            {
                judge = 0;
                break;
            }
        }
        if (judge == 1)
        {
            for (int x = 0; x < length; x++)
            {
                if (x == length - 1)
                {
                    printf("%c", *(str_1 + x));
                }
                else
                {
                    printf("%c", *(str_1 + x));
                    printf("%c",' ');
                }
            }
            free(str_1);
            free(str_list);
            return;
        }
    }
    printf("False");
    free(str_1);
    free(str_list);
    return;
}

int main()
{
    int n;
    std::cin >> n;
    char* str_list = GetStrings(n);
    Func(str_list,n);
    return 0;
}