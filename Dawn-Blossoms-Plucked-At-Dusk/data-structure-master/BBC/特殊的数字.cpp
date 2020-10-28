#include<stdio.h>

int a[3];

int main() {
    for (int i = 100; i <= 999; i++) {
        int index = 0;
        int temp = i;
        while (temp) {
            a[index] = temp % 10;
            index++;
            temp /= 10;
        }
        if (i == (a[0] * a[0] * a[0] + a[1] * a[1] * a[1] + a[2] * a[2] * a[2])) {
            printf("%d\n", i);
        }
    }
    return 0;
}
