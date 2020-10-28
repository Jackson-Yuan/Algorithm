#include<stdio.h>

int a[1000000];
int dp[1000000];

int main() {
    int n;
    scanf("%d", &n);
    int m;
    while (n--) {
        scanf("%d", &m);
        int max = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            dp[i] = a[i];
        }


        for (int i = 1; i < m; i++)//dp[i]i个元素最大子串和
        {
            if (dp[i] < dp[i - 1] + a[i]) {
                dp[i] = dp[i - 1] + a[i];
            } else {
                dp[i] = a[i];
            }
        }
        for (int i = 0; i < m; i++) {
            printf("%d ", dp[i]);
        }
        printf("\n");
        max = dp[0];
        for (int i = 0; i < m; i++) {
            if (max < dp[i]) max = dp[i];
        }
        printf("%d\n", max);
    }
}
/*for(int i=1;i<m;i++)//非连续最大子串和
    {
        for(int j=0;j<i;j++)
        {
            if(b[i]<a[i]+b[j])
            {
                b[i]=a[i]+b[j];
            }
        }
    }*/
