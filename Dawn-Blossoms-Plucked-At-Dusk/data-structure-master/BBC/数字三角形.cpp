#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int map[100][100];
int dp[100][100];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    dp[0][0] = map[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j - 1 >= 0 && j <= i - 1) {
                dp[i][j] = max(dp[i - 1][j - 1] + map[i][j], dp[i - 1][j] + map[i][j]);
            } else if (j - 1 < 0) {
                dp[i][j] = dp[i - 1][j] + map[i][j];
            } else if (j > i - 1) {
                dp[i][j] = dp[i - 1][j - 1] + map[i][j];
            }
        }
    }

    int max = dp[n - 1][0];
    for (int i = 1; i < n; i++) {
        if (max < dp[n - 1][i]) max = dp[n - 1][i];
    }
    printf("%d\n", max);
}
/*
动态规划 理解dp数组含义 推出状态转移方程
也可dfs暴力求解 永远也不要忘记求出最优解的可以直接暴力求解 
*/
