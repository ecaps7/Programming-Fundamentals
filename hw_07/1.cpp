/*输入：
6
5 4 2 6 3 1
输出：
11*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int nums[n];
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int j = 0; j < n; j++)
    {
        for (int k = j; k < n; k++)
        {
            if (nums[j] > nums[k])
            {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}