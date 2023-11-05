/*任务描述
小蓝鲸是个热爱学习的好孩子，再学习了二维数组后他立马想到，数学上的矩阵不就是一个二维数组嘛。于是他在吃饭的时候想到了一个关于矩阵的游戏：给定一个矩阵，如何从外到内，顺时针地将这个矩阵展开？
简单来说，就是由外向内顺时针输出这个二维数组的每一个数字。
你能用学过的编程支持帮他通过这个游戏吗？

输入
第一行两个数字n和m，表示这个是一个n×m的二维数组  (1 ≤ n ≤ 100, 1 ≤ m ≤100)
之后输入n行，每行m个数字，数字用int类型能表示。

输出
由外向内顺时针输出这个二维数组的每一个数字，数字之间用一个空格分隔。*/
/*
 1  2  3  4  5
 6  7  8  9 10
11 12 13 14 15
16 17 18 19 20*/
/*5 4 0
  4 3 1
  3 2 2*/

/*
3 4
 1  2  3 4
10 11 12 5
 9  8  7 6

4 3 0
3 2 1 
*/

#include <iostream>
#include <vector>

using namespace std;

// 定义一个函数，用于按照螺旋顺序输出二维矩阵的元素
void spiralOrder(vector<vector<int>>& matrix) {
    // 如果矩阵为空或者矩阵的第一行为空，则直接返回
    if (matrix.empty() || matrix[0].empty()) {
        return;
    }

    // 初始化四个边界值：上、下、左、右
    int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;

    // 当上边界小于等于下边界且左边界小于等于右边界时，继续循环
    while (top <= bottom && left <= right) {
        // 从左到右遍历上边界
        for (int i = left; i <= right; ++i) {
            cout << matrix[top][i] << " "; // 输出当前元素
        }
        ++top; // 更新上边界

        // 从上到下遍历右边界
        for (int i = top; i <= bottom; ++i) {
            cout << matrix[i][right] << " "; // 输出当前元素
        }
        --right; // 更新右边界

        // 如果上边界小于等于下边界，从右到左遍历下边界
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                cout << matrix[bottom][i] << " "; // 输出当前元素
            }
            --bottom; // 更新下边界
        }

        // 如果左边界小于等于右边界，从下到上遍历左边界
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                cout << matrix[i][left] << " "; // 输出当前元素
            }
            ++left; // 更新左边界
        }
    }
}

int main() {
    // 定义一个3x3的二维矩阵
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // 调用spiralOrder函数，按照螺旋顺序输出矩阵的元素
    spiralOrder(matrix);

    return 0;
}
