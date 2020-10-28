#include<stdio.h>

int a[34][34];

int main() {
    a[0][0] = 1;
    a[1][0] = 1;
    a[1][1] = 1;
    for (int i = 2; i < 34; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
        for (int j = 1; j < i; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
