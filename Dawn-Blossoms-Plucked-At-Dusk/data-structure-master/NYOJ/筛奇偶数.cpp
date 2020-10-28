#include<stdio.h>

int main() {
    int i, n, x;
    scanf("%d", &n);
    while (n) {
        scanf("%d", &x);
        for (i = 1; i <= x; i++) {
            if (i % 2) printf("%d ", i);
        }
        printf("\n");
        for (i = 1; i <= x; i++) {
            if (!(i % 2)) printf("%d ", i);
        }
        n--;
    }

}
