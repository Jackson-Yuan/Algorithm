/*#include<stdio.h>
#include<string.h>
using namespace std;
int dp[30000];
struct good{
	int value;
	int flag;
};
struct good a[25];
int main(){
	int m,n;
	scanf("%d%d",&n,&m);
	
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d",&a[i].value,&a[i].flag);
	}
	memset(dp,0,sizeof(dp));
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(i >= a[j].value){
				if(dp[i] < dp[i - a[j].value]+a[j].value * a[j].flag) dp[i] = dp[i - a[j].value]+a[j].value * a[j].flag;
			}
		}
	}
	
	printf("%d\n",dp[n]);
}*/
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int dp[30][30000];
struct good {
    int value;
    int flag;
};
struct good a[25];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a[i].value, &a[i].flag);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= a[i - 1].value) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1].value] + a[i - 1].value * a[i - 1].flag);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d\n", dp[m][n]);
}
/*
注释代码为错误代码 主要是转移方程及最优子结构出现判断错误 
其实并不难理解 错误代码的最优子结构 本质上与题目意思相背
错误代码思路为 每一次循环 都添加物品 但注意这样会重复添加
所以结束

正确的代码dp[i][j] 利用二维数组直接限制添加物品的个数 保证不会重复添加 
所以自然稳稳当当 
*/
