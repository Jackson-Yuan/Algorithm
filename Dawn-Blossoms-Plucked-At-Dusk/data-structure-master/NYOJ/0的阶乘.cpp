/*
标准解法 求出5与2的个数取最小即可 
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int m;
		scanf("%d",&m);
		int max=0;
		int min=0;
		for(int i=1;i<=m;i++){
			int temp = i;
			while(temp%5==0){
				max++;
				temp=temp/5;
			}
			while(temp%2 == 0){
				min++;
				temp=temp/2;
			}
		}
		if (max>min) printf("%d\n",min);
		else printf("%d\n",max);
	}
} */
#include<stdio.h>
#include<stdlib.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        int sum = 0;
        scanf("%d", &n);
        while (n) {
            n /= 5;//能分解出多少个5的因子，就有多少个0
            sum += n;
        }
        printf("%d\n", sum);
    }
    return 0;
}
/*
此解法与上一个思路一样 但稍微深入了一点，在阶乘的情况下因为因数分解后 2的个数肯定大于等于5的个数
原因 奇数乘奇数等于奇数 奇数乘以偶数，偶数乘以偶数还是偶数 奇数是不可能分离出偶数
所以2的个数大于等于5的个数 
*/ 
