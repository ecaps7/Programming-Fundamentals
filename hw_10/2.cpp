//实现 int atoi(const char *nptr) 的功能
#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);

    if (sentence.empty()) {
        cout << 0 << endl;
        return 0;
    }

    int i = 0;
    while (i < sentence.size() && sentence[i] == ' ') {
        ++i;
    }

    int sign = 1;
    if (sentence[i] == '-' || sentence[i] == '+') {
        sign = (sentence[i++] == '-') ? -1 : 1;
    }

    long long num = 0;

    while (i < sentence.size() && sentence[i] >= '0' && sentence[i] <= '9') {
        num = num * 10 + (sentence[i] - '0');

        if (num * sign > INT_MAX) {
            cout << INT_MAX << endl;
            return 0;
        } else if (num * sign < INT_MIN) {
            cout << INT_MIN << endl;
            return 0;
        }

        ++i;
    }

    cout << num * sign << endl;

    return 0;
}