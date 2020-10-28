#include<stdio.h>
#include<string.h>

int dp[10000];
char b[10001];

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", &b);
        dp[0] = 1;
        for (int i = 1; i < strlen(b); i++) {
            int max = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (b[i] > b[j] && (1 + dp[j]) > max) max = 1 + dp[j];
            }
            dp[i] = max;
        }

        int max = dp[0];
        for (int i = 1; i < strlen(b); i++) {
            if (dp[i] > max) max = dp[i];
        }
        printf("%d\n", max);
    }
}
/*
此题注意不是连续 可以间断
动态规划 dp[i]代表当前位置最多可以有多长的递增子序列
转移方程含义为 每一个与他之前所有的小于他的dp[i]+1 求和取最大值  
*/
