#include<stdio.h>

int main() {
    int a, b;
    char ch;
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%x%c%x", &a, &ch, &b);
        if (ch == '+')
            printf("%o\n", a + b);
        else printf("%o\n", a - b);
    }
}
