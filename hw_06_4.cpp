/*任务描述
给定n个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1，求在该柱状图中，能够勾勒出来的矩形的最大面积 。
输入
2行，第一行是整数n。（1≤n≤100）
第二行有n个非负整数数，代表各个柱子的高度, 所有元素都为int类型。
输出
勾勒出来的矩形的最大面积。*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long max = 0;
    long long nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    long long cop_nums[n];
    for (int i = 0; i < n; i++)
    {
        cop_nums[i] = nums[i];
    }
    sort(cop_nums, cop_nums + n);
    for (int i = 0; i < n; i++)
    {
        long long height = cop_nums[i];
        int length = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] >= height)
            {
                length++;
            }
            else
            {
                long long area = height * length;
                max = (max > area) ? max : area;
                length = 0;
            }
            if (j == n - 1)
            {
                long long area = height * length;
                max = (max > area) ? max : area;
            }
        }
    }
    cout << max;
    return 0;
}

// int main()
// {
//     int n;
//     cin >> n;
//     int nums[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> nums[i];
//     }
//     long long max = 0;
//     for (int j = 0; j < n - 1; j++)
//     {
//         if (nums[j] <= nums[j + 1])
//         {
//             int length = 1;
//             for (int k = j + 1; k <= n - 1; k++)
//             {
//                 if (nums[k] >= nums[k - 1])
//                 {
//                     length++;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             long long area = nums[j] * length;
//             max = max > area ? max : area;
//         }
//     }

//     for (int j = n - 2; j > 0; j--)
//     {
//         if (nums[j] <= nums[j - 1])
//         {
//             int length = 1;
//             for (int k = j - 1; k >= 0; k--)
//             {
//                 if (nums[k] >= nums[k + 1])
//                 {
//                     length++;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             long long area = nums[j] * length;
//             max = max > area ? max : area;
//         }
//     }

//     for (int x = 1; x < n - 1; x++)
//     {
//         if (nums[x] <= nums[x - 1] && nums[x] <= nums[x + 1])
//         {
//             int y = x;
//             int z = x;
//             while (y >= 0)
//             {
//                 if (nums[y] < nums[x])
//                 {
//                     break;
//                 }
//                 y--;
//             }
//             while (z <= n - 1)
//             {
//                 if (nums[z] < nums[x])
//                 {
//                     break;
//                 }
//                 z++;
//             }
//             long long area = nums[x] * (z - y -1);//?
//             max = (max > area) ? max : area;
//         }
//     }

//     for (int i = 1; i < n - 1; i++)
//     {
//         if (nums[i] >= nums[i - 1] && nums[i] >= nums[i + 1])
//         {
//             max = max > nums[i] ? max : nums[i];
//             max = max > (nums[i - 1] * 2) ? max : (nums[i - 1] * 2);
//             max = max > (nums[i + 1] * 2) ? max : (nums[i + 1] * 2);
//             int j = i - 1;
//             int k = i + 1;
//             while (j >= 0 && k <= n - 1)
//             {
//                 if (nums[j] >= nums[k])
//                 {
//                     long long area = nums[k] * (k - j + 1);
//                     max = (max > area) ? max : area;
//                 }
//                 else
//                 {
//                     int area = nums[j] * (k - j + 1);
//                     max = (max > area) ? max : area;
//                 }

//                 if (j - 1 >= 0 && k <= n - 1)
//                 {
//                     if (nums[j - 1] > nums[k + 1])
//                     {
//                         j--;
//                     }
//                     else if (nums[j - 1] < nums[k + 1])
//                     {
//                         k++;
//                     }
//                     else
//                     {
//                         j--;
//                         k++;
//                     }
//                 }
//                 else if (j == 0)
//                 {
//                     k++;
//                 }
//                 else
//                 {
//                     j--;
//                 }
//             }
//         }
//     }
//     cout << max;
//     return 0;
// }纪念一下写了几个小时却只对了2个测试用例的代码