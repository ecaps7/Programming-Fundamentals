/*删去一个最高分和最低分*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int grades[n];
    int mmax = 0; 
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &grades[i]);
        sum += grades[i];
        if (grades[i] > mmax)
        {
            mmax = grades[i];
        }
    }
    int mmin = grades[0];
    for (int i = 0; i < n; i++)
    {    
        if (grades[i] < mmin)
        {
            mmin = grades[i];
        }
    } 
    sum = sum - mmax  - mmin;
    double ans = (double)sum / (n - 2);
    printf("%.2lf", ans);
    return 0;
}