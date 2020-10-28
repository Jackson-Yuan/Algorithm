#include<stdio.h>

int main() {
    int z, a, b, i, min = 0, max = 0;
    int m, n;

    while (scanf("%d %d", &a, &b)) {
        int temp = 0;

        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }
        m = a;
        n = b;
        while (m) {
            i = n % m;
            n = m;
            max = m;
            m = i;
        }
        min = (a * b) / max;
        printf("%d %d\n", max, min);
    }
}

