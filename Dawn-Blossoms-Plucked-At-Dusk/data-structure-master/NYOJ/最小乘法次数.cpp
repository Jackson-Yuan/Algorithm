#include<stdio.h>

int a[10000];

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int m;
        int count = 0;
        scanf("%d", &m);
        if (m == 1) {
            printf("0\n");
            continue;
        }
        while (m != 1) {
            if (m % 2 != 0) {
                m--;
                count++;
            } else {
                m = m / 2;
                count++;
            }
        }
        printf("%d\n", count);
    }
}
/*
   ��һ������� ż�� ֱ�ӿ����Զ� ����
   ��Ϊ����  
*/
