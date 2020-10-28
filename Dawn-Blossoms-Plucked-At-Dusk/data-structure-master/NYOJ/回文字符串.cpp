#include<stdio.h>

char a[1000];
int dp[1001][1001] = {0};

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {

        scanf("%s", a);
        int index = 0;
        while (a[index] != '\0') {
            index++;
        }
        int sum = index / 2;
        for (int i = 0; i <= sum; i++) {
            dp[0][i] = 0;
            dp[i][0] = 0;
        }
        for (int i = 1; i <= sum; i++) {
            for (int j = 1; j <= sum; j++) {
                if (a[i - 1] == a[index - j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        printf("%d\n", (sum - dp[sum][sum]) * 2);
    }
}
