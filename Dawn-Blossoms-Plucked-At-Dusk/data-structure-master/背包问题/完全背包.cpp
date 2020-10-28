#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int w[100];
int v[100];
int dp[100][100];

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
            dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
/**
与01背包不同 01背包每种只能放一个 所以需要转移到dp[i - 1]行
但每种完全背包可以无限放 所以转移到dp[i]行即可 
*/
