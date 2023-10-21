/*任务描述
天冷了，南大限量卫衣开始销售。现拼团出售，男生款3件共a元，女生款3件共b元，情侣款2件共c元（只有情侣可以穿情侣款，也可以选择不穿情侣款）。某书院有m+k个男生，n+k个女生，其中k对情侣，他们都要购买，计算购买最小花费。
输入
1行，6个整数 m n k a b c，以空格隔开，代表题目所述含义。
(0≤ m,n,k,a,b,c ≤1000)
输出：
1行，1个整数，代表最少花费*/
#include <iostream>
using namespace std;

int rounding(int x)
{
    if (x % 3 == 0)
    {
        return x/3;
    }
    else
    {
        return (x / 3 + 1);
    }
}

int main()
{
    int m, n, k, a, b, c;
    int cost_min = 0;
    cin >> m >> n >> k >> a >> b >> c;
    if (k == 0)
    {
        int m_1 = rounding(m);
        int n_1 = rounding(n);
        cost_min = m_1 * a + n_1 * b;
    }
    else
    {
        int cost;
        cost_min = a * rounding(m + k) + b * rounding(n + k);
        for (int i = 0; i <= k; i++)
        {
            int m_1 = rounding(m + k - i);
            int n_1 = rounding(n + k - i);
            cost = m_1 * a + n_1 * b + i * c;
            if (cost < cost_min)
            {
                cost_min = cost;
            }
        }
    }
    cout << cost_min;
    return 0;
}