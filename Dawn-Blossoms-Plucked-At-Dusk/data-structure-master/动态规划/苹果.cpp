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
ע�ʹ���Ĵ�Ҳ����ȷ�� ��ʵ���߷���˼·��һ�µ�
ֻ����һ����һά���� һ���Ƕ�ά����
�ڴ����ַ��� ��һ��û����ʾ�����Ʒ��뱳��ƻ���ĸ��� 
��ע�� Ƕ�����ڲ��ѭ�� Ӧ�������� ��������
����ԭ������
���߷�����˼·��ʵ��һ�� ���������һ������� ����һ��������µ���������������������� 
����Ĵ����� ��ȷ��Ϊ0����ʱ������ ����0��������µ�����һ��������� �Դ����Ƴ�2�� 3�������
���������������� ��Ϊ���������Ҫ����ǰ�������� ��dp[2]Ҫ����dp[1]���� �������� ����dp[2]Ҫ����Ϊ�����������
��ô��Ҫ����dp[1]Ϊ1������� ���������� dp[1]�Ѿ�����Ϊ��������� ������Ȼ�ʹ��� �����������ʱ������ѵ���ѡ��
��Ϊ�����������ɺ� ǰ��Ĳ���Ҫ���������� �ǳ����� Ҫ�㹦���� 

��ע�ʹ��� ��ͬ ��Ϊ�ɶ�ά���鱣��1�� 2������������ÿ���������� ����������������ν 
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
