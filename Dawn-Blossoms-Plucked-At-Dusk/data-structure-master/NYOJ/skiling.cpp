#include<stdio.h>

int a[100][100];
int count, max;
int m, n;

void dfs(int x, int y) {
    if ((y + 1) < n && a[x][y] > a[x][y + 1]) {
        count++;
        dfs(x, y + 1);
        count--;
    }
    if ((y - 1) >= 0 && a[x][y] > a[x][y - 1]) {
        count++;
        dfs(x, y - 1);
        count--;
    }
    if ((x + 1) < m && a[x][y] > a[x + 1][y]) {
        count++;
        dfs(x + 1, y);
        count--;
    }
    if ((x - 1) >= 0 && a[x][y] > a[x - 1][y]) {
        count++;
        dfs(x - 1, y);
        count--;
    }
    if (count > max) {
        max = count;

    }
}

int main() {
    int z;
    scanf("%d", &z);
    while (z--) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        count = max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                count = 1;
                dfs(i, j);
            }
        }
        printf("%d\n", max);
    }
}
