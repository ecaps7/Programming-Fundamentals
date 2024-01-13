#include <iostream>
using namespace std;

void partReverse(int nums[], int start, int end)
{
    while(start < end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

int main()
{
    int n;
    cin >> n;
    int* nums = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    //找到最长递降后缀
    int m = 1;
    int index = n - 1;//最长递降后缀前的数的索引
    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i - 1] <= nums[i])
        {
            index = i - 1;
            break;
        }
        m++;
    }
    int index_1 = index + 1;//
    while (nums[index_1] > nums[index])
    {
        index_1++;
        if (index_1 == n)
        {
            break;
        }
    }
    index_1--;
    swap(nums[index], nums[index_1]);
    partReverse(nums, index + 1, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << nums[i] << endl;
        }
        else
        {
            cout << nums[i] << " ";
        }
    }
    delete[] nums;
    return 0;
} 