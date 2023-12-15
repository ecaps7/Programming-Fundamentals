/*任务描述
合并具有重叠部分的区间。

输入
第一行正整数n（n<=100），代表区间个数。
接下来n行，每行2个正整数，空格隔开（左数<右数），代表区间范围。整数都为INT类型。

输出：
合并后的从小到大所有区间，每个一行

输入
4
1 3
2 6
8 10
10 11
输出
1 6
8 11
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Interval
{
    int left;
    int right;
};

bool comp(const Interval& i1, const Interval& i2)
{
    return i1.left < i2.left;
}

int main()
{
    int n;
    cin >> n;
    vector<Interval> info(n);
    vector<Interval> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> info[i].left;
        cin >> info[i].right;
    }
    sort(info.begin(), info.end(), comp);
    Interval current = info[0];
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (info[i].left <= current.right)
        {
            current.right = max(info[i].right, current.right);
        }
        else
        {
            ans.push_back(current);
            current = info[i];
            count++;
        }
    }
    ans.push_back(current);
    count++;
    for (int i = 0; i < count; i++)
    {
        cout << ans[i].left << " " << ans[i].right << endl;
    }
    return 0;
}