#include<stdio.h>

int a[101];//价格
int b[101];//重要度 
int dp[26][30001];//行个数，列价格 
int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {
    int count;
    scanf("%d", &count);
    while (count--) {
        int sum, n;
        scanf("%d%d", &sum, &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i], &b[i]);
        }
        for (int i = 0; i <= sum; i++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (a[i] > j) dp[i][j] = dp[i - 1][j];
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i] * b[i]);
                }
            }
        }
        printf("%d\n", dp[n][sum]);
    }
}
/*
经典动态规划 
状态dp[i][j]：i代表物品个数，j代表总钱数
状态转移： if(a[i]>j) dp[i][j]=dp[i-1][j]; 
 else
{
	dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]*b[i]);
}   
思路 ：通过前i个物品在j的金额下的最大值，动态的选择下一个金额或增加一个物品的情况下的最大众 与01背包相仿	  		
*/
