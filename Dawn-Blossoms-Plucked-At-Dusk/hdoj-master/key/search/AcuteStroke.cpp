/**
 * 算法笔记 p281
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
int graph[60][1000][1000];
bool visited[60][1000][1000];
int m, n, l, t;
struct direction {
    int x;
    int y;
    int z;
};
struct point {
    int x;
    int y;
    int z;
};
vector<direction> directions = {{1,  0,  0},
                                {-1, 0,  0},
                                {0,  1,  0},
                                {0,  -1, 0},
                                {0,  0,  1},
                                {0,  0,  -1}};

int bfs(int x, int y, int z) {
    int countValue = 0;
    queue<point> q;
    point start;
    start.x = x;
    start.y = y;
    start.z = z;
    q.push(start);
    visited[start.x][start.y][start.z] = true;
    while (!q.empty()) {
        point cur = q.front();
        q.pop();
        ++countValue;
        for (int i = 0; i < directions.size(); ++i) {
            int tmpX = cur.x + directions[i].x;
            int tmpY = cur.y + directions[i].y;
            int tmpZ = cur.z + directions[i].z;
            if (tmpX < 0 || tmpX >= l || tmpY < 0 || tmpY >= m || tmpZ < 0 || tmpZ >= n) continue;
            if (graph[tmpX][tmpY][tmpZ] == 1 && !visited[tmpX][tmpY][tmpZ]) {
                visited[tmpX][tmpY][tmpZ] = true;
                point next;
                next.x = tmpX;
                next.y = tmpY;
                next.z = tmpZ;
                q.push(next);
            }
        }
    }
    return countValue;
}

int main() {

    cin >> m >> n >> l >> t;

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> graph[i][j][k];
            }
        }
    }

    int res = 0;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if (!visited[i][j][k] && graph[i][j][k] == 1) {
                    int countValue = bfs(i, j, k);
                    if (countValue >= t) res += countValue;
                }
            }
        }
    }
    cout << res << endl;
    return 0;


}