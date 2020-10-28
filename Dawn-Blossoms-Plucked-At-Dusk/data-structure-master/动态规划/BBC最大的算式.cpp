/*#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[30];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int index = 1;
	long long sum = a[0];
	for(int i = 0 ; i < n-1-k ; i++){
		sum += a[index];
		index++;
	}
	for(int i = index ; i < n ; i++){
		sum *= a[i];
	}
	
	printf("%lld\n",sum);
}*/
#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
long long a[40];
long long dp[40][40];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
        dp[i][0] = sum;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1 && j <= k; j++) {
            for (int k = 2; k <= i; k++) {
                dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] * (dp[i][0] - dp[k - 1][0]));
            }
        }
    }

    printf("%lld\n", dp[n][k]);
}
/*
��̬�滮 �ؼ�����dp��������ʾ������ ������ȷ����״̬ת�Ʒ��̱�ܺ��Ƶ�(���������ʾΪǰi��������j���˺ŵ����ֵ)  ״̬ת�Ʒ��̼�����
��Ҫ˼·Ϊ ��Ϊ�˺Ÿ��������� ���Ը���dp��������� ��������ѭ�� ��һ��ָ������ �ڶ���ָ���ų˺ŵĸ��� ������ѭ��������ǰ�˺ŵ�λ��
���dp[i][j]�����ֵ 
*/
