#include<stdio.h>
#include<string.h>

char a[8];
int b[8];

int main() {
    scanf("%s", a);
    int n = strlen(a);
    for (int i = 0; i < n; i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            b[i] = a[i] - '0';
        } else {
            b[i] = a[i] - 'A' + 10;
        }
    }
    long long sum = 0;
    long long temp = 1;
    for (int i = n - 1; i >= 0; i--) {
        sum += b[i] * temp;
        temp *= 16;
    }
    printf("%lld\n", sum);
}
/*
��������ܼ� ��ע���Ѿ�����Χ�� ��Ϊintռ4�ֽ� 32λ һλ����λ
8λʮ������ 32λ  �޷�ƥ��
temp �����϶��ᱨint 
��long long 
ע�������ʽ 
*/ 
