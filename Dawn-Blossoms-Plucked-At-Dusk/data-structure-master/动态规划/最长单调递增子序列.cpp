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
����ע�ⲻ������ ���Լ��
��̬�滮 dp[i]����ǰλ���������ж೤�ĵ���������
ת�Ʒ��̺���Ϊ ÿһ������֮ǰ���е�С������dp[i]+1 ���ȡ���ֵ  
*/
