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
        for (int i = 0; i < m; i++)//�ӵ����
        {
            for (int j = 0; j <= m - i - 1; j++)//�ӵĸ���
            {
                for (int k = 0; k < n; k++)//Ҫ�ӵ�����
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
//��������Ӵ��ͣ�״̬��b[i]��ʾǰi�� һ��������i������������Ӵ���  ��ΪҪ��Ϊ���������Ե�ǰλ��һ��Ҫ��ǰһ���������ӱȽ�ȷ��ֵ 
//״̬ת�ƣ�b[i]<a[i]+b[i-1] 
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
//��չ����ά����������Ӿ���ͣ���ά��һά��һά����������Ӵ��� 
