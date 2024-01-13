/*给定一个经过编码后的字符串，请返回它解码后的原字符串。

编码规则为： k[encoded_str]，表示方括号中的 encoded_str 正好重复 k 次。
题目保证:

k >= 2
encoded_str 中仅包含小写英文字母
解码后的原字符串长度不会超过 10000，并且仅包含小写英文字母。

输入：
14
2[a]3[b]define
输出：
aabbbdefine

输入：
13
11[ab]inlcude
输出：
abababababababababababinclude*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    string ans;
    int times = 0;
    string x;
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            times = 10 * times + str[i] - '0';
            continue;
        }
        else if (str[i] == '[')
        {
            int count = 0;
            for (int j = i + 1; str[j] != ']'; j++)
            {
                x += str[j];
                count++;
            }
            i = i + count + 1;//?
            for (int k = 0; k < times; k++)
            {
                ans = ans + x;
            }
            times = 0;
            x.clear();
        }
        else
        {
            ans += str[i];
        }
    }
    cout << ans << endl;
    return 0;
}