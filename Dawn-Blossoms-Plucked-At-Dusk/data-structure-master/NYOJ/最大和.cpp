#include<stdio.h>

int a[100][100];
int b[100];
int dp[100];

int main() {
    int m, n, count;
    scanf("%d", &count);
    while (count--) {
        int max = -99999999;
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < m; i++)//加的起点
        {
            for (int j = 0; j <= m - i - 1; j++)//加的个数
            {
                for (int k = 0; k < n; k++)//要加的列数
                {
                    int sum = 0;
                    for (int z = i; z <= i + j; z++) {
                        sum = sum + a[z][k];
                    }
                    b[k] = sum;
                    dp[k] = sum;
                }
                for (int a = 1; a < n; a++) {
                    if (dp[a] < b[a] + dp[a - 1]) {
                        dp[a] = b[a] + dp[a - 1];
                    }
                }
                int flag = dp[0];
                for (int a = 1; a < n; a++) {
                    if (flag < dp[a]) flag = dp[a];
                }
                if (flag > max) max = flag;
            }
        }
        printf("%d\n", max);
    }

}
//最大连续子串和，状态：b[i]表示前i个 一定包括第i个的最大连续子串和  因为要求为连续，所以当前位置一定要与前一个进行连接比较确定值 
//状态转移：b[i]<a[i]+b[i-1] 
/*	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	
	for(int i=1;i<n;i++)
	{
	   if(b[i]<a[i]+b[i-1])
	   {
	   	 b[i]=a[i]+b[i-1];
	   }
	}
	int max=a[0];
	for(int i=1;i<n;i++)
	{
		if(max<b[i]) max=b[i];
	}
	printf("%d\n",max);*/
//拓展：二维矩阵求最大子矩阵和，二维化一维，一维求最大连续子串和 
