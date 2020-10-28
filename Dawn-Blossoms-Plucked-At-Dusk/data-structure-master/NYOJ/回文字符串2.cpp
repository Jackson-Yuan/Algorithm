#include <stdio.h>
#include <string.h>

char s1[1001], s2[1001];
int dp[1001][1001];

int max(int n, int m) {
    return n > m ? n : m;
}

int main() {
    int n, i, j, k;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s1);
        k = strlen(s1);
        for (i = k - 1; i >= 0; i--) {
            s2[k - i - 1] = s1[i];
        }
        memset(dp, 0, sizeof(dp));
        for (i = 1; i <= k; i++) {
            for (j = 1; j <= k; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        printf("%d\n", k - dp[k][k]);
    }
}  
