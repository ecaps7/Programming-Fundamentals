/*任务描述
从键盘中输入一个英文句子，寻找其中最长的单词。（注意输入句末的标点为句号,且不会出现其他符号）有多个相同长度的最长单词时输出第一个出现的最长单词。

输入
一个英文句子

输出：
英文句子中最长的英文单词

样例输入：
Happy new year.
样例输出：
Happy*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;
    string word;
    getline(cin, sentence, '.');
    int start = 0;
    int end = 0;
    int length = 0;
    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] == ' ')
        {
            end = i - 1;
            if (length < (end - start + 1))
            {
                length = end - start + 1;
                word = sentence.substr(start, length);
            }
            start = i + 1;
        }
    }
    if (length >= sentence.size() - start)
    {
        cout << word << endl;
    }
    else
    {
        word = sentence.substr(start, sentence.size() - start);
        cout << word << endl;
    }
    return 0;
}