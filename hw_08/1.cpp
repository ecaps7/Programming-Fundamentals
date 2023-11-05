//给定一个非负整数数组，找到使所有数组元素相等所需的最小移动数，其中每次移动可将选定的一个元素加1或减1。
/*输入
2行，第1行1个整数，代表输入数组长度m。（1≤m≤300）
第2行m个数，代表这个数组，所有元素都为int类型。
输出
最小移动数
0 1 2 3 4
0 2 3 4 5//0~
1 3 6 7 8*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int m;
    cin >> m;
    int nums[m];
    long long count = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> nums[i];
    }
    sort(nums, nums + m);
    if (m % 2 == 0)
    {
        long long count_1 = nums[m - 1] - nums[m/2-1];
        long long count_2 = nums[m/2] - nums[0];
        for (int i = 0; i <= m / 2 - 2; i++)
        {
            count_1 += (nums[m - 2 - i] - nums[i]);// 0 ~ m - 2    m-2-i-i=1 
        }
        for (int j = 1; j <= m / 2 - 1; j++)
        {
            count_2 += (nums[m - j] - nums[j]);// 1 ~ m - 1
        }
        count = count_1 < count_2 ? count_1 : count_2;
    }
    else
    {
        for (int k = 0; k < (m - 1)/2; k++)
        {
            count += (nums[m - 1 - k] - nums[k]);
        }
    }
    cout << count << endl;
    return 0;
}