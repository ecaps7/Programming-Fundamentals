//高精度加减法 13/15
#include <iostream>
#include <cstring>
using namespace std;

struct BigInt
{
    int len;
    int sign;
    char data[1001];
};

BigInt read_bigint() {
    struct BigInt bigint;
    // TODO(p3): Add your code here for reading a BigInt object from terminal
    cin >> bigint.len;
    cin.getline(bigint.data, 1001);
    for (int i = 0; i < strlen(bigint.data) - 1; i++)
    {
        bigint.data[i] = bigint.data[i + 1];
    }
    bigint.data[strlen(bigint.data) - 1] = '\0';
    bigint.sign = (bigint.data[0] == '-') ? -1 : 1;
    return bigint;
}

void add(char num1[], char num2[], BigInt& ret)
{
    ret.sign = 1;
    int carry = 0;
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    int max_length = max(length1, length2) + 1;
    int min_length = min(length1, length2);
    ret.len = max_length + 1;
    for (int i = 0; i < max_length; i++)
    {
        int digit1 = i < length1 ? num1[length1 - i - 1] - '0' : 0;
        int digit2 = i < length2 ? num2[length2 - i - 1] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        ret.data[max_length - i - 1] = sum % 10 + '0';
        carry = sum / 10;
    }
    ret.data[max_length] = '\0';
}

// num1 减去 num2, 这里假定 num1, num2 均为正数
void subtract(char num1[], char num2[], BigInt& ret)
{
    ret.sign = 1;
    int borrow = 0;
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    char temp[1001]{};
    if ((length1 < length2) || (length1 == length2 && strcmp(num1, num2) < 0))
    {
        swap(num1, num2);
        length1 = strlen(num1);
        length2 = strlen(num2);
        ret.sign = -1;
    }
    ret.len = length1 + 2;
    for (int i = 0; i < length1 + 1; i++)
    {
        int digit1 = i < length1 ? num1[length1 - i - 1] - '0' : 0;
        int digit2 = i < length2 ? num2[length2 - i - 1] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0)
        {
            borrow = 1;
            diff += 10;
        }
        else
        {
            borrow = 0;
        }
        ret.data[length1 - i] = diff + '0';
    }
    ret.data[length1 + 1] = '\0';
}

// return bigint1 + bigint2
BigInt add_bigint(struct BigInt bigint1, struct BigInt bigint2) {
    struct BigInt ret;
    // TODO(p3): Add your code here, and return sum of bigint1 and bigint2
    struct BigInt tmp1 = bigint1;
    struct BigInt tmp2 = bigint2;

    if (bigint1.sign == -1) {
        memmove(tmp1.data, tmp1.data + 1, strlen(tmp1.data));
    }

    if (bigint2.sign == -1) {
        memmove(tmp2.data, tmp2.data + 1, strlen(tmp2.data));
    }
    if (tmp1.sign == 1 && tmp2.sign == 1)
    {
        add(tmp1.data, tmp2.data, ret);
    }
    else if (tmp1.sign == -1 && tmp2.sign == -1)
    {
        add(tmp1.data, tmp2.data, ret);
        ret.sign = -1;
    }
    else
    {
        subtract(tmp1.data, tmp2.data, ret);
    }
    return ret;
}

// return bigint1 - bigint2
struct BigInt sub_bigint(struct BigInt bigint1, struct BigInt bigint2) {
    struct BigInt ret;

    struct BigInt tmp1 = bigint1;
    struct BigInt tmp2 = bigint2;

    if (bigint1.sign == -1) {
        memmove(tmp1.data, tmp1.data + 1, strlen(tmp1.data));
    }

    if (bigint2.sign == -1) {
        memmove(tmp2.data, tmp2.data + 1, strlen(tmp2.data));
    }

    if (tmp1.sign == 1 && tmp2.sign == 1) {
        subtract(tmp1.data, tmp2.data, ret);
    }
    else if (tmp1.sign == -1 && tmp2.sign == 1) {
        add(tmp1.data, tmp2.data, ret);
        ret.sign = -1;
    }
    else if (tmp1.sign == 1 && tmp2.sign == -1) {
        add(tmp1.data, tmp2.data, ret);
    }
    else {
        subtract(tmp1.data, tmp2.data, ret);
        ret.sign *= -1;
    }

    return ret;
}
void print_bigint(struct BigInt bigint) {
    // TODO(p3): Add your code here for printing a BigInt object to terminal
    int i = 0;
    int judge = 0;
    while (bigint.data[i] != '\0')
    {
        if (judge == 0 && bigint.data[i] != '0')
        {
            judge = 1;
        }
        i++;
    }
    if (judge == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        if (bigint.sign == -1 && bigint.data[1] != '0')
        {
            cout << "-";
        }
        int j = 0;
        while (bigint.data[j] == '0')
        {
            j++;
        }
        while (bigint.data[j] != '\0')
        {
            cout << bigint.data[j];
            j++;
        }
        cout << endl;
    }
}

int main() {
    struct BigInt bigint1 = read_bigint();
    struct BigInt bigint2 = read_bigint();
    print_bigint(add_bigint(bigint1, bigint2));
    print_bigint(sub_bigint(bigint1, bigint2));
    return 0;
}