#include<stdio.h>
#include<iostream>
#include<algorithm>

int a[6];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 10000; i <= 999999; i++) {
        int index = 0;
        int temp = i;
        while (temp) {
            a[index] = temp % 10;
            index++;
            temp = temp / 10;
        }
        int flag = 0;
        int begin = 0;
        int end = index - 1;
        while (begin <= end) {
            if (a[begin] != a[end]) {
                flag = 1;
                break;
            }
            begin++;
            end--;
        }
        if (flag == 0) {
            int sum = 0;
            for (int i = 0; i < index; i++) {
                sum += a[i];
            }
            if (sum == n) {
                for (int i = 0; i < index; i++) {
                    printf("%d", a[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
