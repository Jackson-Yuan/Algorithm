/*
��׼�ⷨ ���5��2�ĸ���ȡ��С���� 
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
            n /= 5;//�ֽܷ�����ٸ�5�����ӣ����ж��ٸ�0
            sum += n;
        }
        printf("%d\n", sum);
    }
    return 0;
}
/*
�˽ⷨ����һ��˼·һ�� ����΢������һ�㣬�ڽ׳˵��������Ϊ�����ֽ�� 2�ĸ����϶����ڵ���5�ĸ���
ԭ�� ������������������ ��������ż����ż������ż������ż�� �����ǲ����ܷ����ż��
����2�ĸ������ڵ���5�ĸ��� 
*/ 
