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
基本步骤很简单 但注意已经超范围了 因为int占4字节 32位 一位符号位
8位十六进制 32位  无法匹配
temp 变量肯定会报int 
用long long 
注意输出格式 
*/ 
