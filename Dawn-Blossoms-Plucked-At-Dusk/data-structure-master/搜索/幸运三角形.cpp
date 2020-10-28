#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
/*int result[20][20];*/
int temp[20] = {0, 0, 4, 6, 0, 0, 12, 40, 0, 0, 171, 410, 0, 0, 1896, 5160, 0, 0, 32757, 59984};
int n;

/*int sum;
int a,b;
void dfs(int index){
	if(index == n){
		a=0;
		b=0;
		for(int i = 0 ; i < n ; i++){
			if(result[0][i] == 1) a++;
			if(result[0][i] == 2) b++;
		}
		for(int i = 1 ; i < n ; i++){
			for(int j = 0 ; j < n-i ; j++){
				if(result[i-1][j+1] != result[i-1][j]){
					result[i][j] = 2;
					b++;
				}else{
					result[i][j] = 1;
					a++;
				}
			}
			
		}
		if(a == b) sum++;
		return;
	}
	result[0][index] = 1;
	dfs(index+1);
    result[0][index] = 2;
    dfs(index+1);
}*/
int main() {
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", temp[n - 1]);
    }
}
/*
此题就是利用dfs穷举第一行的情况 推导出接下来几行的情况
但会n大于15会超时
此处的一个技巧
打表 
*/
