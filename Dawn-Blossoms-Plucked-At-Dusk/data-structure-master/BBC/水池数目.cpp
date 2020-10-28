#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int map[100][100];
int visited[100][100];
int m, n;

void dfs(int x, int y) {
    if (visited[x][y] == 1) return;
    if (map[x][y] == 0) return;
    visited[x][y] = 1;
    if (x - 1 >= 0) dfs(x - 1, y);
    if (x + 1 < m) dfs(x + 1, y);
    if (y - 1 >= 0) dfs(x, y - 1);
    if (y + 1 < n) dfs(x, y + 1);
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%d%d", &m, &n);
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        int flag = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1 && visited[i][j] == 0) {
                    dfs(i, j);
                    flag++;
                }
            }
        }
        printf("%d\n", flag);
    }
}
/*
与bbc全球变暖类似 只不过在试探时注意边界条件 
*/
