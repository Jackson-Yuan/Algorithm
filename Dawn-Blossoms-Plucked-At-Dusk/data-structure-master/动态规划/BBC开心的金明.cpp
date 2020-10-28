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
ע�ʹ���Ϊ������� ��Ҫ��ת�Ʒ��̼������ӽṹ�����жϴ��� 
��ʵ��������� �������������ӽṹ ����������Ŀ��˼�౳
�������˼·Ϊ ÿһ��ѭ�� �������Ʒ ��ע���������ظ����
���Խ���

��ȷ�Ĵ���dp[i][j] ���ö�ά����ֱ�����������Ʒ�ĸ��� ��֤�����ظ���� 
������Ȼ���ȵ��� 
*/
