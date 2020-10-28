#include<stdio.h>

int f(int n) {
    if (n == 1) return 1;
    else return n * f(n - 1);
}

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = f(i + 1);
    }
    int n;
    scanf("%d", &n);
    while (n--) {
        int m;
        scanf("%d", &m);
        for (int i = 9; i >= 0; i--) {
            if (m >= a[i]) m -= a[i];

        }
        if (m == 0) printf("Yes\n");
        else printf("No\n");
    }
}
