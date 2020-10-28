#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;
int dp[30000];
int person[100];
int value[6] = {100, 50, 10, 5, 2, 1};

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        int sumValue = 0;
        if (n == 0) break;
        int max = -1;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            scanf("%d", &person[i]);
            if (person[i] > max) max = person[i];
        }

        for (int i = 0; i <= max; i++) {
            dp[i] = i;
        }

        for (int i = 1; i <= max; i++) {
            for (int j = 0; j < 6; j++) {
                if (i >= value[j]) {
                    if (dp[i - value[j]] + 1 < dp[i]) dp[i] = dp[i - value[j]] + 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            sumValue += dp[person[i]];
        }
        printf("%d\n", sumValue);
    }
}
