/*汉诺塔问题*/
#include<iostream>
using namespace std;

void hanoi(char a, char b, char c, int n)
{
    if (n == 1)
    {
        cout << a << " -> " << c << endl;
    }
    else
    {
        hanoi(a, c, b, n - 1);
        cout << a << " -> " << c << endl;
        hanoi(b, a, c, n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    hanoi('A', 'B', 'C', n);
    return 0;
}
/*#include <iostream>
using namespace std;

void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disk 1 from " << A << " to " << C << endl;
    } else {
        hanoi(n - 1, A, C, B);
        cout << "Move disk " << n << " from " << A << " to " << C << endl;
        hanoi(n - 1, B, A, C);
    }
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}*/