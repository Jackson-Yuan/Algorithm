#include<stdio.h>

void an(int n) {
    if (n == 1) {
        printf("sin(1");
    } else {
        if (n % 2 == 0) {
            an(n - 1);
            printf("-sin(%d", n);
        } else {
            an(n - 1);
            printf("+sin(%d", n);
        }
    }
}

void sn(int n) {
    /*��������*/
    for (int i = 0; i < n - 1; i++) {
        printf("(");
    }
    for (int i = 1; i <= n; i++) {
        an(i);
        for (int j = 0; j < i; j++) {
            printf(")");
        }
        printf("+");
        printf("%d", n + 1 - i);
        /*+1 ��ʱ����Ҫ������*/
        if (i != n) printf(")");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    sn(n);
    printf("\n");
}
/*
���ҹ��� ���ĵ� 
*/
