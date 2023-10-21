//这是第5次作业第3题的循环解法，感谢拔尖班一位同学的帮助！
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#define _N 30

int n, r;

int ans[_N];

int cnt = 0;
bool flag[_N];

int cur_val, cur_pt;

void print_ans() {
    for (int i = 1; i <= r; i++) {
        printf("%d ", ans[i]);
    }
    puts("");
}

int main() {
    scanf("%d%d", &n, &r);
    cur_val = 1, cur_pt = 1;
    while (true) {
        if (cur_pt > r) {
            print_ans(); // print_ans()
            if (flag[cnt--]) {
                goto LABEL1;
            } else {
                goto LABEL2;
            }
        }
        if (cur_val > n) { 
            if (flag[cnt--]) {
                goto LABEL1;
            } else {
                goto LABEL2;
            }
        }
        ans[cur_pt] = cur_val; // ans[cur_pt] = cur_val
        cur_val++; cur_pt++; // cur_val + 1, cur_pt + 1
        flag[++cnt] = true; // continue1
        continue; // calc
        LABEL1: cur_pt--;
        flag[++cnt] = false; // continue2
        continue; // calc
        LABEL2: cur_val--;
        if (cnt == 0) {
            break;
        }
        if (flag[cnt--]) {
            goto LABEL1;
        } else {
            goto LABEL2;
        }
    }
    return 0;
}