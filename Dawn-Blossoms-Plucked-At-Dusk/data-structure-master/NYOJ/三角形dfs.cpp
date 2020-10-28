#include<stdio.h>

int a[101][101];
int sum = 0, max = 0;
int m;

void dfs(int n, int x)//dfs深度优先搜索，适合一路到底的思路，使用的同时注意回溯
{
    if (n > m) {
        if (sum > max) max = sum;
        return;
    }
    for (int i = x; i <= x + 1; i++) {
        sum = sum + a[n][i];
        n++;
        dfs(n, i);
        n--;
        sum = sum - a[n][i];
    }
}

int main() {
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    sum = a[1][0];
    dfs(2, 0);
    printf("%d\n", max);
}
