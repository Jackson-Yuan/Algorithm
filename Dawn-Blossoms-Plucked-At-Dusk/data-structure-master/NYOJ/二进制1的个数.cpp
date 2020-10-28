#include<stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);
    while (n--) {
        int count = 0;
        scanf("%d", &m);
        while (m) {
            if (m % 2 == 1) count++;
            m = m / 2;
        }
        printf("%d\n", count);
    }
}
