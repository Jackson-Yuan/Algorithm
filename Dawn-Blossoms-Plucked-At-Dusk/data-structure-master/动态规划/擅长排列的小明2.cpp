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
˼·�� 
    ��Ϊ�˼�������������Ai�����i�����֣�

    ����A1һֱ��1������A2ֻ����2��3��

    1.��A2=2ʱ����A2��An�����У�2~n���൱�ڴ�A1��An-1�����У�1~n-1������ÿ�����ֶ���1����һ����f[n-1]�������

    2.��A2=3ʱ��A3����Ϊ2��4��5��

        ��A3=2ʱ��A4һ������4����ʱ��A4��An�����У�4~n)�൱�ڴ�A1��An-3�����У���ÿ�����ֶ���3����һ����f[n-3]�������

        ��A3=4ʱ������A4ȡ��ȡ2���������γ�������������У��ʴ�����������ܷ�����

        ��A3=5ʱ������ֻ������1 ,3, 5,7,9......10,8,6,4,2,����һ����1�������

����������f[n]=f[n-3]+f[n-1]+1��(n>3)
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
��ȻҲ��������dfs �� ���ᳬʱ
��Ϊ��������������Ƶ�
��� 
*/



