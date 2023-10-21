/*任务描述
从m（0<m≤26）个小写英文字母中选出k（0<k≤m）个字母，按字典序打印所有结果。
输入
第一行是两个整数m,k。
第二行是m个给定的小写字母。
输出
每行一种结果（字典序排列），字母之间用空格隔开。*/
//此题
#include <iostream>
#include <algorithm>
using namespace std;

int m, k;

char ans[27];

void print_ans()
{
    for (int i = 1; i <= k; i++)
    {
        cout << ans[i] << " " ;
    }
    cout << endl;
}

void calc(int cur_val, int cur_pt, char alphabet[])
{
    if (cur_pt > k)
    {
        print_ans();
        return;
    }

    if (cur_val > m)
    {
        return;
    }

    ans[cur_pt] =  alphabet[cur_val];
    calc(cur_val + 1, cur_pt + 1, alphabet);
    calc(cur_val + 1, cur_pt, alphabet);
}

int main()
{
    cin >> m >> k;
    char alphabet[m + 1];
    alphabet[0] = 'Z';
    for (int i = 1; i <= m; i++)
    {
        cin >> alphabet[i];
    }
    sort(alphabet, alphabet + m + 1);
    char letter = alphabet[0];
    calc(1, 1, alphabet);
    return 0;
}