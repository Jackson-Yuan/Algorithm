#include<stdio.h>

char map[100][100];
int visited[100][100];
int check[10000];

void dfs(int x, int y, int flag) {
    if (map[x][y] == '.') return;
    if (visited[x][y] == 1) return;
    visited[x][y] = 1;
    if (map[x - 1][y] == '#' && map[x + 1][y] == '#' && map[x][y + 1] == '#' && map[x][y - 1] == '#')
        check[flag]++;
    dfs(x - 1, y, flag);
    dfs(x + 1, y, flag);
    dfs(x, y + 1, flag);
    dfs(x, y - 1, flag);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < n; j++) {
            scanf("%c", &map[i][j]);
        }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == '#' && visited[i][j] == 0) {
                dfs(i, j, flag);
                flag++;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < flag; i++) {
        if (check[i] == 0) sum++;
    }
    printf("%d\n", sum);
}
/*此题思路利用dfs来判断岛屿
具体流程为，随意的找岛屿的其中一个点，从这个点开始dfs，同时传入一个标记，标记从这个点开始形成的岛屿，这样这个岛屿的其他点便不会存在其他标记
(因为在dfs中会把每个搜素过的点都标记为已访问，而dfs开始的条件就是要未被访问) ,所以check数组里面的索引都是每个不同岛屿里面的一个代表，特别的
是不会淹没的岛屿，对应check数组里的值为非0
*/
