/*任务描述
假设有一个面值为n (1<=n<=10000)的纸币，给定三种不同零钱以及它们的数量：a元、b元和c元，数目分别为x张、y张和z张。如果把这张n元的纸币换成零钱，一共有多少种不同的换法？

输入
7个正整数，以空格分隔，分别表示n，a，b，c，x，y，z。其中1<=n<=10000，1<=a,b,c<=100，0<=x,y,z<=1000000。

输出
不同的换法的种数。*/
#include <iostream>
using namespace std;

int main()
{
	int n, a, b, c, x, y, z;
	cin >> n >> a >> b >> c >> x >> y >> z;
	long count = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= (n - i); j++)
		{
			if ((n - a * i - b * j) % c == 0 && (n - a * i - b * j) / c >= 0 && (n - a * i - b * j) / c <= z)
			{
				count++;
			}
		}
	}
	cout << count;
	return 0;
}