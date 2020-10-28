#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int map[9][9] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 1, 0, 0, 1, 0, 1,
        1, 0, 0, 1, 1, 0, 0, 0, 1,
        1, 0, 1, 0, 1, 1, 0, 1, 1,
        1, 0, 0, 0, 0, 1, 0, 0, 1,
        1, 1, 0, 1, 0, 1, 0, 0, 1,
        1, 1, 0, 1, 0, 1, 0, 0, 1,
        1, 1, 0, 1, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1,
};
int visited[9][9];
int mindistance = 100000;
int m, n;

void dfs(int x, int y, int distance) {
    if (visited[x][y] == 1) return;
    if (x == m && y == n) {
        if (mindistance > distance) mindistance = distance;
        return;
    }
    visited[x][y] = 1;
    if (map[x + 1][y] == 0) dfs(x + 1, y, distance + 1);
    if (map[x - 1][y] == 0) dfs(x - 1, y, distance + 1);
    if (map[x][y + 1] == 0) dfs(x, y + 1, distance + 1);
    if (map[x][y - 1] == 0) dfs(x, y - 1, distance + 1);
    visited[x][y] = 0;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int x, y;
        scanf("%d%d%d%d", &x, &y, &m, &n);
        memset(visited, 0, sizeof(visited));
        mindistance = 100000;
        dfs(x, y, 0);
        printf("%d\n", mindistance);
    }
}
/*此题依然是访问的标记与还原只不过在理解上更进一步，每次的标记与还原，不需要再向每个方向之前标记，这个方向的dfs调用完之后还原，只需在一开始时标记，当前函数执行完之前还原就行
这种写法与每个方向之前标记，这个方向的dfs调用完之后还原的写法本质上是一样的
*/
