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
    ̰�Ĳ���
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
    /*��̬�滮����*/
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
��̬�滮�������:
dp[i]�����ǮΪi�ļ�Ǯ����Ҫ����ֽ��
dp[i]��ѡֵ ����ݿ�ѡֽ����ֵ����	if(i >= value[j])  dp[i - value[j]] + 1 ����ÿ�ε���� ѡȡ��Сֵ
Ҳ����˵ dp[6]����Сֵ ������dp[5]+1 dp[2]+1 dp[3]+1 ���ߵ���Сֵ(���ݿ�ѡֽ����ֵ���Ʋ�) 
���յó�dp[ash] 
*/
/*
��̬��̰�ĵ����� 
̰�ĵ�ÿ��ѡ�� ����ֱ��ѡȡ
��̬���ǰ����ѡ���������������������һ�� ѡȡ���Ž�
��̰���붯̬�������ѭ����ѭ�����֪���� 
*/ 
