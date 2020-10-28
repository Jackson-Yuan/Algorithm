#include<stdio.h>

int a[101][101];
int b[101][101];

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            b[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        b[n][i] = a[n][i];
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            b[i][j] = max(b[i + 1][j], b[i + 1][j + 1]) + a[i][j];
        }
    }

    printf("%d\n", b[1][0]);
}
