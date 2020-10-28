#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>

using namespace std;
struct apple {
    int size;
    int value;
};
struct apple a[1000];
int dp[1000];

int main() {
    while (1) {
        int n, v;
        scanf("%d%d", &n, &v);
        memset(dp, 0, sizeof(dp));
        if (n == 0 && v == 0) break;
        /*for(int z = 0 ; z <= v ; z++){
                printf("%d ",dp[z]);
            }
            printf("\n");*/
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i].size, &a[i].value);
        }
        for (int i = 0; i < n; i++) {
            for (int j = v; j >= a[i].size; j--) {
                dp[j] = max(dp[j], dp[j - a[i].size] + a[i].value);
            }
            /*for(int z = 0 ; z <= v ; z++){
                printf("%d ",dp[z]);
            }
            printf("\n");*/
        }

        printf("%d\n", dp[v]);
    }
}
/*
注释代码的答案也是正确的 其实两者方法思路是一致的
只不过一个是一维数组 一个是二维数组
在处理手法上 第一种没有显示的限制放入背包苹果的个数 
但注意 嵌套在内层的循环 应该是逆序 正序会出错
究其原因如下
两者方法的思路其实都一样 都是先算放一个的情况 再在一个的情况下迭代出迭代出放两个的情况 
上面的代码中 先确定为0个的时候的情况 再在0个的情况下迭代出一个的情况下 以此类推出2个 3个的情况
但如果利用正序迭代 因为后面迭代需要依靠前面来迭代 如dp[2]要依赖dp[1]迭代 由于正序 假设dp[2]要迭代为放两个的情况
那么需要依赖dp[1]为1个的情况 但由于正序 dp[1]已经迭代为两个的情况 所以自然就错了 所以逆序遍历时才是最佳迭代选择
因为当本身迭代完成后 前面的不需要自身来迭代 非常巧妙 要点功力的 

而注释代码 则不同 因为由二维数组保存1个 2个。。。。下每个体积的情况 所以正序逆序无所谓 
*/
/*
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct apple{
	int size;
	int value;
};
int dp[1003][1003];
struct apple a[1003];
int main(){
	int n,v;
	while(1){
		scanf("%d%d",&n,&v);
		if(n == 0 && v == 0) break;
		for(int i = 0 ; i < n ; i++){
			scanf("%d%d",&a[i].size,&a[i].value);
		}
		memset(dp,0,sizeof(dp));
		
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= v ; j++){
				if(j >= a[i - 1].size){
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1].size] + a[i - 1].value);
				}else{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		
		printf("%d\n",dp[n][v]);
	}
}
*/
