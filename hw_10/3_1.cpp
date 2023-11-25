//高精度加减法 AC
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct BigInt
{
    int len;
    int sign;
    char data[1001];
};

struct BigInt read_bigint() {
    struct BigInt bigint;
    // TODO(p3): Add your code here for reading a BigInt object from terminal
    string input;
    cin >> bigint.len;
    cin >> input;
    bigint.sign = 1;
    if (input[0] == '-')
    {
        bigint.sign = -1;
        for (int i = 0; i < bigint.len; i++)
        {
            bigint.data[i] = input[i + 1];
        }
    }
    else
    {
        for (int i = 0; i < bigint.len; i++)
        {
            bigint.data[i] = input[i];
        }
    }
    return bigint;
}

void print_bigint(struct BigInt bigint) {
   // TODO(p3): Add your code here for printing a BigInt object to terminal
    int judge = 0;
    int j = 0;
    for (int i = 0; i < bigint.len; i++)
    {
        if (bigint.data[i] != '0')
        {
            judge = 1;
        }
    }
    if (judge == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        if (bigint.sign == -1)
        {
            cout << "-";
        }
        while (bigint.data[j] == '0')
        {
            j++;
        }
        while (j < bigint.len)
        {
            cout << bigint.data[j];
            j++;
        }
        cout << endl;
    }
}

struct BigInt sub_bigint(struct BigInt bigint1, struct BigInt bigint2);

// return bigint1 + bigint2
struct BigInt add_bigint(struct BigInt bigint1, struct BigInt bigint2) {
    struct BigInt ret;
    // TODO(p3): Add your code here, and return sum of bigint1 and bigint2
    
    if (bigint1.sign * bigint2.sign == 1)
    {
        ret.sign = bigint1.sign;
        int carry = 0;
        int max_len = max(bigint1.len, bigint2.len);
        ret.len = max_len + 1;
        for (int i = 0; i < max_len; i++)
        {
            int digit1 = i < bigint1.len ? bigint1.data[bigint1.len - i - 1] - '0' : 0;
            int digit2 = i < bigint2.len ? bigint2.data[bigint2.len - i - 1] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            ret.data[max_len - i] = sum % 10 + '0';
            carry = sum / 10;
        }
        ret.data[0] = carry + '0';
        //ret.data[max_len + 1] = '\0';
    }
    else if (bigint1.sign == -1 && bigint2.sign == 1)
    {
        bigint1.sign = 1;
        ret = sub_bigint(bigint1, bigint2);
        ret.sign *= -1;
    }
    else
    {
        bigint2.sign = 1;
        ret = sub_bigint(bigint1, bigint2);
    }
    return ret;
}

// return bigint1 - bigint2
struct BigInt sub_bigint(struct BigInt bigint1, struct BigInt bigint2) {
    struct BigInt ret;
    // TODO(sub): Add your code here, and return sub of bigint1 and bigint2
    if ((bigint1.sign == 1 && bigint2.sign == 1) || (bigint1.sign == -1 && bigint2.sign == -1))
    {
        ret.sign = (bigint1.sign + bigint2.sign) / 2;
        if (bigint1.len < bigint2.len ||(bigint1.len == bigint2.len && strcmp(bigint1.data, bigint2.data) < 0))
        {
            swap(bigint1, bigint2);
            ret.sign *= -1;
        }
        int borrow = 0;
        int len = bigint1.len;
        ret.len = len;
        for (int i = 0; i < len; i++)
        {
            int digit1 = bigint1.data[bigint1.len - i - 1] - '0';
            int digit2 = i < bigint2.len ? bigint2.data[bigint2.len - i - 1] - '0': 0;
            int diff = digit1 - digit2 - borrow;
            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            ret.data[len - 1 - i] = diff + '0';
        }
    }
    else if (bigint1.sign == -1 && bigint2.sign == 1)
    {
        bigint1.sign = 1;
        ret = add_bigint(bigint1, bigint2);
        ret.sign *= -1;
    }
    else
    {
        bigint2.sign = 1;
        ret = add_bigint(bigint1, bigint2);
    }
    return ret;
}

int main() {
    struct BigInt bigint1 = read_bigint();
    struct BigInt bigint2 = read_bigint();
    print_bigint(add_bigint(bigint1, bigint2));
    print_bigint(sub_bigint(bigint1, bigint2));
    return 0;
}