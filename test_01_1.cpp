/*任务描述
现在有n个互不相同的整数，小蓝鲸不关心最大和最小，他只想知道第二大和第二小的数，写个程序帮帮他吧。
输入
分为两行，第一行一个整数n，2<=n<=100
第二行为n个互不相同用空格分隔的整数，其中每个整数的范围为-10^8到10^8。
输出
两个用空格分隔的数，分别为n个数中第二大和第二小的数。*/
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long nums[n];
	if (n == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			cin >> nums[i];
		}
		int max_2 = nums[0] < nums[1] ? nums[0] : nums[1];
		int min_2 = nums[0] > nums[1] ? nums[0] : nums[1];
		cout << max_2 << " " << min_2;
        return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	long max_1 = nums[0];
	long min_1 = nums[0];
	for (int i = 0; i < n; i++)
	{
		max_1 = max_1 > nums[i] ? max_1 : nums[i];
		min_1 = min_1 < nums[i] ? min_1 : nums[i];
	}
    long max_2 = min_1;
    long min_2 = max_1;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] == max_1 || nums[i] == min_1)
		{
			continue;
		}
		max_2 = max_2 > nums[i] ? max_2 : nums[i];
        min_2 = min_2 < nums[i] ? min_2 : nums[i];
	}
	cout << max_2 << " " << min_2;
    return 0;
}