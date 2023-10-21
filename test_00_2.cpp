/*任务描述
小蓝鲸是一个钢琴爱好者，他喜欢黑键和白键轮流弹奏。
现在他遇到了一串连续的由黑块和白块构成的序列，他想知道他按照序列顺序分别轮流弹奏黑块和白块，最多能弹奏多少下？
在题目中，黑块和白块分别由 B 和 W 字符来表示。我们需要获得最长的连续交错的 BWBW... 或 WBWB... 序列。

输入
第一行输入一个整数 n，表示输入序列的长度
第二行输入长度为 n 的由 B 和 W 字符构成的文本序列。

0 <= n <= 100
文本序列仅包含字符 B 和 W
输出
一个整数，表示按照当前弹奏规则最多能弹奏的次数。*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
    }
    else
    {
    char words[n];
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    char word = words[0];
    for (int i = 0; i < n; i++)
    {
        if (words[i] != word)
        {
            count += 1;
            word = words[i];
        }
    }
    cout << count;
    } 
    return 0;
}