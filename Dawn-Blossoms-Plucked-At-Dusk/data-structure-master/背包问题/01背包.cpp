#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
int w[100];
int v[100];
int dp[100][100];//前i个物品体积为j的最大价值 
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }
}
/**
每个物品都有两种选择 要么放 要么不放
利用此规律 可以进行动态规划 
*/
