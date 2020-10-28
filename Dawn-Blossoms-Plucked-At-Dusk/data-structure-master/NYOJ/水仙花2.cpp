#include<stdio.h>

int main() {
    int a, b, c, n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) return 0;
        a = n / 100;
        b = (n / 10) % 10;
        c = n % 10;
        if (a * 100 + b * 10 + c == a * a * a + b * b * b + c * c * c) printf("Yes\n");
        else printf("No\n");
    }
}
