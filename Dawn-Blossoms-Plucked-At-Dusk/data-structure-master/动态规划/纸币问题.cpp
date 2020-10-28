#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

/*int main(){
	int value[20];
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&value[i]);
	}
	int ash;
	scanf("%d",&ash);
	
	sort(value,value+n);
	int count = 0;
    贪心策略
	for(int i = n - 1 ; i >= 0 ; i--){
		if(ash > value[i]){
			int temp = ash/value[i];
			count += temp;
			ash = ash - temp * value[i];
		}
		if(ash == 0) break;
	}
	cout<<count<<endl;
}*/
int main() {
    int value[20];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }
    int ash;
    scanf("%d", &ash);
    int dp[20];
    /*动态规划策略*/
    for (int i = 0; i <= ash; i++) {
        dp[i] = i;
    }
    for (int i = 1; i <= ash; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= value[j]) {
                if (dp[i - value[j]] + 1 < dp[i]) dp[i] = dp[i - value[j]] + 1;
            }
        }
    }

    printf("%d\n", dp[ash]);
}
/*
动态规划策略详解:
dp[i]代表价钱为i的价钱最少要多少纸币
dp[i]的选值 因根据可选纸币面值来定	if(i >= value[j])  dp[i - value[j]] + 1 遍历每次的情况 选取最小值
也就是说 dp[6]的最小值 来自于dp[5]+1 dp[2]+1 dp[3]+1 三者的最小值(根据可选纸币面值来推测) 
最终得出dp[ash] 
*/
/*
动态与贪心的区别 
贪心的每次选择 都是直接选取
动态则是把这次选择所能引发的情况都遍历一遍 选取最优解
看贪心与动态的最外层循环的循环体就知道了 
*/ 
