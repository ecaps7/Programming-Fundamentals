/*假设一套题目中有n道题目，对于第i道题目有一个难度系数k_i。我们称一套题目的难度是平衡的当且仅当对于连续的两道编号为a和a+1的题目，其难度系数的差值的绝对值应当小于等于一个平衡系数x。
例如当平衡系数是2的时候，1 1 1 2为一套平衡的题目，1 1 1 4是一套不平衡的题目。
现在助教孙昊出好了一套题，共计有n道题目，但他出题的时候压根没想过这么多事情，因此这套题目很可能是不平衡的，他希望聪明的你能够帮助他整理题目。我们至少需要从中删除掉多少道题目才能使得这套题目恢复平衡性呢？你可以对题目的顺序进行重新排列测试用例：
输入：
5 3
1 9 5 3 10
输出：2
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    long n;
    long x;
    cin >> n >> x;
    vector<int> deg(n);
    for (long i = 0; i < n; i++)
    {
        cin >> deg[i];
    }
    sort(deg.begin(), deg.end());
    
    vector<int> point;
    int num;
    for (long k = 1; k < n; k++)
    {
        if (deg[k] - deg[k - 1]> x)
        {
            num = k;
            point.push_back(num);
        }
    }
    
    if (point.size() == 1)
    {
        if (point[0] * 2 <= n)
        {
        cout << (point[0]);
        }
        else
        {
        cout << (n - point[0]);
        }
    }
    
    else if(point.size() > 1)
    {
        point.push_back(0);
        point.push_back(n - 1);
        sort(point.begin(), point.end());
        long max = point[1] - point[0];
        for (long j = 1; j < point.size(); j++)
        {
            if ((point[j] - point[j - 1]) > max)
            {
                max = point[j] - point[j - 1];
            }
        }
        cout << n - max;
    }
    else if(point.size() == 0)
    {
        cout << 0;
    }

    return 0;
}