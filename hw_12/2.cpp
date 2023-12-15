/*任务描述
朋友的朋友也是朋友。你和你所有的直接朋友以及间接朋友构成一个朋友圈。
给定NxN的矩阵M，如果M[i][j]=1，则i和j是直接朋友。求朋友圈数量。

输入
第1行1个正数N。
接下来N行，每行N个数字（N<20）。

输出
朋友圈数量

输入：
4
1 1 0 0
1 1 1 0
0 1 1 0
0 0 0 1
输出：
2
0和1是直接朋友，1和2是直接朋友，0和2是间接朋友，三人构成朋友圈。3独自一人构成朋友圈。所以一共有2个朋友圈。

1 0 1 0
0 1 0 0
1 0 1 0
0 0 0 1

0, 1; 0, 2; 0, 4; 1, 2; 1, 4
*/
#include <iostream>
#include <vector>

using namespace std;

void dfs(int i, vector<vector<int>>& M, vector<bool>& visited) {
    for (int j = 0; j < M.size(); ++j) {
        if (M[i][j] == 1 && !visited[j]) {
            visited[j] = true;
            dfs(j, M, visited);
        }
    }
}

int findCircle(vector<vector<int>>& M) {
    int n = M.size();
    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, M, visited);
            ++count;
        }
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> M(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> M[i][j];
        }
    }

    cout << findCircle(M) << endl;

    return 0;
}
