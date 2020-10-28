#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
/*int num[56];
int main(){
	int n;
	num[1]=1;
	num[2]=1;
	num[3]=2;
	for(int i = 4 ; i <= 55 ; i++){
		num[i] = num[i-1] + num[i-3] + 1;
	}
	while(scanf("%d",&n) != EOF){
		printf("%d\n",num[n]);
	}
}*/
/*
思路： 
    （为了简便起见，我们用Ai代表第i个数字）

    由于A1一直是1，所以A2只能是2或3。

    1.当A2=2时，从A2到An的排列（2~n）相当于从A1到An-1的排列（1~n-1）（把每个数字都加1），一共有f[n-1]种情况。

    2.当A2=3时，A3可能为2，4，5。

        当A3=2时，A4一定等于4，此时从A4到An的排列（4~n)相当于从A1到An-3的排列（把每个数字都加3），一共有f[n-3]种情况。

        当A3=4时，不管A4取不取2，都不能形成满足题意的排列，故此种情况不可能发生。

        当A3=5时，排列只可能是1 ,3, 5,7,9......10,8,6,4,2,所以一共有1种情况。

综上所述，f[n]=f[n-3]+f[n-1]+1；(n>3)
*/
int visited[56];
int n;
int countValue;

void dfs(int prefix, int index) {
    if (index == n) {
        countValue++;
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (abs(i - prefix) <= 2 && visited[i] == 0) {
            visited[i] = 1;
            dfs(i, index + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        countValue = 0;
        memset(visited, 0, sizeof(visited));
        dfs(1, 1);
        printf("%d\n", countValue);
    }
}
/*
当然也可以利用dfs 求 但会超时
因为输入个数是有限制的
打表 
*/



