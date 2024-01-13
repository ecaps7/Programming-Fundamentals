/*任务描述
小蓝鲸总是在下课后就迅速的前往食堂吃饭，但是他在前往食堂的路上总是会被一些现充秀恩爱暴击。
假设一个自然数编号代表一个情侣或是小蓝鲸，现在前往食堂的路上有n对情侣，他们都是成双成对的，只有小蓝鲸不是，请找出小蓝鲸的编号吧
(翻译一下就是有n-1个数出现了两遍，请你找出那个只出现一次的数)
输入
两行
第一行包含一个数n代表出现了多少个自然数（1⩽n⩽1e5）
第二行包含2n−1个数，每个数的大小x（1⩽x⩽10 * n）
输出：
小蓝鲸的编号*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int nums[2 * n - 1];
    for (int i = 0; i < 2 * n - 1; i++)
    {
        cin >> nums[i];
    }
    int ans = 0;
    sort(nums, nums + 2 * n - 1);
    if (nums[0] != nums[1])
    {
        cout << nums[0];
        return 0;
    }
    else if (nums[2 * n - 2] != nums[2 * n - 3])
    {
        cout << nums[2 * n - 2];
        return 0;
    }
    for (int i = 1; i < 2 * n - 2; i++)
    {
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
        {
            ans = nums[i];
            break;
        }
    }
    cout << ans;
    return 0;    
}