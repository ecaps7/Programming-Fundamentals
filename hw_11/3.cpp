#include <iostream>
using namespace std;

int Va, Vb, Vc; // 容量

bool find(int a, int b, int c, int a0, int b0, int c0, int k)
{
    if (a == a0 && b == b0 && c == c0)
    {
        return true;
    }
    if (k == 0)
    {
        return false;
    }
    for (int j = 0; j < 6; j++)
    {
        int a1 = a;
        int b1 = b;
        int c1 = c;
        switch (j)
        {
        case 0:
            b = (a + b) > Vb ? Vb : (a + b);
            a = 0;
            if (find(a, b, c, a0, b0, c0, k - 1))
            {
                return true;
            }
            break;
        case 1:
            c = (a + c) > Vc ? Vc : (a + c);
            a = 0;
            if (find(a, b, c, a0, b0, c0, k - 1))
            {
                return true;
            }
            break;
        case 2:
            a = (a + b) > Va ? Va : (a + b);
            b = 0;
            if (find(a, b, c, a0, b0, c0, k - 1))
            {
                return true;
            }
            break;
        case 3:
            c = (c + b) > Vc ? Vc : (c + b);
            b = 0;
            if (find(a, b, c, a0, b0, c0, k - 1))
            {
                return true;
            }
            break;
        case 4:
            a = (a + c) > Va ? Va : (a + c);
            c = 0;
            if (find(a, b, c, a0, b0, c0, k - 1))
            {
                return true;
            }
            break;
        case 5:
            b = (b + c) > Vb ? Vb : (b + c);
            c = 0;
            if (find(a, b, c, a0, b0, c0, k - 1))
            {
                return true;
            }
            break;
        default:
            break;
        }
        a = a1;
        b = b1;
        c = c1;
    }
    return false;
}

int main()
{
    int k; // 目标次数
    cin >> k;
    cin >> Va >> Vb >> Vc;
    int a, b, c; // 初始情况
    cin >> a >> b >> c;
    int a0, b0, c0; // 目标情况
    cin >> a0 >> b0 >> c0;
    if (find(a, b, c, a0, b0, c0, k))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}