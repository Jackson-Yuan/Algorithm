#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
struct good {
    int time;
    int value;
};
int dp[103][1003];
struct good a[100];

int main() {
    int t, m;
    scanf("%d%d", &t, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a[i].time, &a[i].value);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= t; j++) {
            if (j >= a[i - 1].time) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1].time] + a[i - 1].value);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d\n", dp[m][t]);
}
/*
01背包变式  
经典的动态规划 与开心的金明思路想法 及可能出错的地方一致 
*/
