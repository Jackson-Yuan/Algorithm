#include<stdio.h>
#include<string.h>

int dp[25][25];

int main() {
    int k;
    scanf("%d", &k);
    memset(dp, 0, sizeof(dp));
    dp[2][2] = 2;
    for (int i = 3; i <= k; i++) {
        for (int j = 2; j <= i; j++) {
            if (j == 2) {
                dp[i][j] = i * (i - 1);
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    int sum = 0;
    for (int i = 2; i <= k; i++) {
        sum += dp[k][i];
    }

    printf("%d\n", sum);
}
/*
�����Ŀ�Ķ�̬�滮״̬ת�Ʒ��� �����Լ������߼��Ƴ��� ���ǰ���dp����ı�ʾ�����Լ�������ֵ�Ƴ� Ҳ�Ƿ��� 
*/
