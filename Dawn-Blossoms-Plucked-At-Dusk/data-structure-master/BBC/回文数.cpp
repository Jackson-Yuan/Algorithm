#include<stdio.h>

int a[4];

int main() {
    for (int i = 1000; i <= 9999; i++) {
        int temp = i;
        for (int j = 0; j < 4; j++) {
            a[j] = temp % 10;
            temp = temp / 10;
        }
        int begin = 0;
        int end = 3;
        int flag = 0;
        while (begin <= end) {
            if (a[begin] != a[end]) {
                flag = 1;
                break;
            }
            begin++;
            end--;
        }
        if (flag == 0) printf("%d\n", i);
    }
}
