/*任务描述
小蓝鲸喜欢打扑克但不喜欢理牌，请按照从大到小2AKQJT9876543的顺序帮他理好牌吧。（这里的T实际上就是扑克牌的10）。要求用指针来进行理牌，不能出现a[1]这类语法。

输入
一行少于100的字符（你有可能需要整理100张牌！），只包含2AKQJT9876543这些字符

输出：
整理好的牌

样例1：
输入：
555JQKA
输出：
AKQJ555*/
#include <iostream> // 引入输入输出流库
#include <string>   // 引入字符串库
using namespace std; // 使用标准命名空间

// 比较两个字符的大小
int compare(char a, char b) {
    string order = "AKQJT98765432"; // 定义一个字符串，表示扑克牌的大小顺序
    return order.find(a) - order.find(b); // 返回两个字符在order中的位置差值，用于比较大小
}

// 理牌函数
void sortCards(const string &input, string &output) {
    for (int i = 0; i < input.size(); i++) { // 遍历输入的字符串
        for (int j = 0; j < output.size(); j++) { // 遍历输出的字符串
            if (compare(input[i], output[j]) > 0) { // 如果输入的字符大于输出的字符
                output.insert(j, 1, input[i]); // 将输入的字符插入到输出字符串的指定位置
                break; // 跳出内层循环
            }
        }
    }
}

int main() {
    string input; // 定义一个字符串变量，用于存储输入的扑克牌序列
    cin >> input; // 从标准输入读取扑克牌序列
    string output; // 定义一个字符串变量，用于存储排序后的扑克牌序列
    sortCards(input, output); // 调用理牌函数，对输入的扑克牌序列进行排序
    cout << output << endl; // 将排序后的扑克牌序列输出到标准输出
    return 0; // 程序正常结束，返回0
}
