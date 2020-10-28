#include<stdio.h>

char a[20];

int main() {
    long long value;
    scanf("%lld", &value);
    int index = 0;
    if (value == 0) {
        printf("0\n");
        return 0;
    }
    while (value) {
        int temp = value % 16;
        if (temp < 10) {
            a[index] = '0' + temp;
        } else {
            a[index] = 'A' + temp - 10;
        }
        index++;
        value /= 16;
    }
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", a[i]);
    }
    printf("\n");
    return 0;
}
/*
注意输入输出格式 
*/
