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
动态规划 关键在于dp数组所表示的意义 意义明确了则状态转移方程便很好推导(此题数组表示为前i个数中有j个乘号的最大值)  状态转移方程见代码
主要思路为 因为乘号个数有限制 所以更加dp数组的意义 建立三层循环 第一层指明个数 第二次指明放乘号的个数 第三次循环遍历当前乘号的位置
算出dp[i][j]的最大值 
*/
