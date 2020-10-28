#include<stdio.h>

int a[101];//�۸�
int b[101];//��Ҫ�� 
int dp[26][30001];//�и������м۸� 
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
���䶯̬�滮 
״̬dp[i][j]��i������Ʒ������j������Ǯ��
״̬ת�ƣ� if(a[i]>j) dp[i][j]=dp[i-1][j]; 
 else
{
	dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]*b[i]);
}   
˼· ��ͨ��ǰi����Ʒ��j�Ľ���µ����ֵ����̬��ѡ����һ����������һ����Ʒ������µ������ ��01�������	  		
*/
