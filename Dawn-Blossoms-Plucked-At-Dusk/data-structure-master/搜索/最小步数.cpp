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
/*������Ȼ�Ƿ��ʵı���뻹ԭֻ����������ϸ���һ����ÿ�εı���뻹ԭ������Ҫ����ÿ������֮ǰ��ǣ���������dfs������֮��ԭ��ֻ����һ��ʼʱ��ǣ���ǰ����ִ����֮ǰ��ԭ����
����д����ÿ������֮ǰ��ǣ���������dfs������֮��ԭ��д����������һ����
*/
