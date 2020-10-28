#include<stdio.h>

int result[20][20];
int show[20];
int n;
int index;
int count;

void dfs(int index) {
    if (index == n) {
        if (count < n - count) return;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (show[i] == 1 && show[j] == 1 && i != j) {
                    if (result[i][j] != 1) return;
                }

                if (show[i] == 1 && show[j] == 0 && i != j) {
                    if (result[i][j] != 0) return;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (show[i] == 1) printf("%d ", i + 1);
        }
        printf("\n");
        return;
    }
    show[index] = 0;
    dfs(index + 1);
    show[index] = 1;
    count++;
    dfs(index + 1);
    count--;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &result[i][j]);
        }
    }
    count = 0;
    dfs(0);
}
/*大致思路 利用dfs实现全排列 穷举出所有芯片好坏情况 然后用好芯片与其他芯片做测试 如果结果与result数组不一致的话 则此情况失效
同时不要忘记细节 好的个数大于坏的个数 

同时 还有一种方法 因为好的芯片个数大于坏的芯片个数 所以 一个芯片被其他芯片测试时 result[i][j] = 1 超过半数 则为好芯片(假设i为被测试芯片)
想到这个 我也是服 
*/
