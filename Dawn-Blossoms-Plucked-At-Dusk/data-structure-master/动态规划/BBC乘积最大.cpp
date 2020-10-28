#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;
int s[100][100];
int dp[100][100];
char str[100];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j == i) s[i][j] = str[j] - '0';
            else s[i][j] = s[i][j - 1] * 10 + str[j] - '0';
        }
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = s[0][i - 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int x = j; x < i; x++) {
                dp[i][j] = max(dp[i][j], dp[x][j - 1] * s[x][i - 1]);
            }
        }
    }

    cout << dp[n][k] << endl;
}
/**
此题大意为 给你一个数字字符串 在里面添加指定个数乘号 求出最大值  
拿到题 标准一脸懵逼
解法如下:
由于为字符串 所以新建数组存放各个字符串的分割值 如字符串1234  分割 1 12 123 1234 2 23 234 3 34 4
 dp[i][j]为前i为数中j个乘号的最大值  利用递推式 dp[i][j] = max(dp[i][j], dp[x][j - 1] * s[x][i - 1]);
 求出最大值 
*/
