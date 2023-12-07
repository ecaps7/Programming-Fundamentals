#include <iostream>
using namespace std;
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int func(int x)
{
    int sum = 0;
    if (x == 0)
    {
        return 6;
    }
    while (x > 0)
    {
        sum += num[x % 10];
        x = x / 10;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            int k = i + j;
            if (func(i) + func(j) + func(k) == n - 4)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}