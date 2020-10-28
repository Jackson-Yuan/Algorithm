#include<stdio.h>

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        printf("%d\n", a * (a + 1) * b * (b + 1) / 4);
    }
}
