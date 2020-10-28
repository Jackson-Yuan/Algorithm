#include<stdio.h>

int add(int x) {
    int t = 0, i;
    if (x == 1 || x == 2) t = 1;
    else {
        t = add(x - 1) + add(x - 2);
    }
    return t;
}

int main() {
    int n, x;
    scanf("%d", &n);
    while (n) {
        scanf("%d", &x);
        printf("%d", add(x));
        printf("\n");
        n--;
    }
}
