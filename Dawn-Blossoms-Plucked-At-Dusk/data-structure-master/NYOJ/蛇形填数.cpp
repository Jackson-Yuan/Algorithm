#include<stdio.h>
#include<string.h>

//#define max 100
int main() {
    int a[100][100];
    int n, x, y, t = 0;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    y = n - 1;
    x = 0;
    a[x][y] = 1;
    t = 1;
    while (t < n * n) {
        while (y + 1 < n && a[x][y + 1] == 0) {
            a[x][++y] = ++t;
        }
        while (x + 1 < n && a[x + 1][y] == 0) {
            a[++x][y] = ++t;
        }
        while (y - 1 >= 0 && a[x][y - 1] == 0) {
            a[x][--y] = ++t;
        }
        while (x - 1 >= 0 && a[x - 1][y] == 0) {
            a[--x][y] = ++t;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
