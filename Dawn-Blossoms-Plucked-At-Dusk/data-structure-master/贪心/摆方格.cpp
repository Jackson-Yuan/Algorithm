#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int a[20][20];
int visited[100];
int n;
int maxvalue = -1;

void dfs(int x, int y, int value) {
    a[x][y] = value;
    visited[value] = 1;
    if (x == n - 1 && y == n - 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        int sum = 0;
        int sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i][n - i - 1];
            sum2 += a[i][i];
        }
        int result;
        if (sum > sum2) result = sum;
        else result = sum2;
        if (result > maxvalue) maxvalue = result;
        visited[value] = 0;
        return;
    }
    for (int i = 1; i <= n * n; i++) {
        if (!visited[i]) {
            if (y + 1 == n) dfs(x + 1, 0, i);
            else dfs(x, y + 1, i);
        }
    }
    visited[value] = 0;
}

int main() {
    while (cin >> n) {
        maxvalue = -1;
        for (int i = 1; i <= n * n; i++) {
            memset(visited, 0, sizeof(visited));
            dfs(0, 0, i);
        }
        printf("%d\n", maxvalue);
    }
}
