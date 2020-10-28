/**
 * hdoj-1253
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;
struct point {
    int x;
    int y;
    int z;
    int step;
};
int graph[100][100][100];
bool visited[100][100][100];

int main() {
    int count;
    scanf("%d", &count);
    while (count--) {
        int a, b, c, maxValue;
        scanf("%d %d %d %d", &a, &b, &c, &maxValue);
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                for (int k = 0; k < c; ++k) {
                    scanf("%d", &graph[i][j][k]);
                }
            }
        }

        memset(visited, 0, sizeof(visited));
        point start;
        start.x = 0;
        start.y = 0;
        start.z = 0;
        start.step = 0;
        visited[start.x][start.y][start.y] = true;
        queue<point> q;
        q.push(start);
        int time = -1;

        while (!q.empty()) {
            point current = q.front();
            q.pop();
            int tmpX = current.x, tmpY = current.y, tmpZ = current.z;
            if (tmpX == a - 1 && tmpY == b - 1 && tmpZ == c - 1) {
                time = current.step;
                break;
            }
            if (tmpX - 1 >= 0 && graph[tmpX - 1][tmpY][tmpZ] == 0 && !visited[tmpX - 1][tmpY][tmpZ]) {
                visited[tmpX - 1][tmpY][tmpZ] = true;
                point next;
                next.x = tmpX - 1;
                next.y = tmpY;
                next.z = tmpZ;
                next.step = current.step + 1;
                q.push(next);
            }
            if (tmpX + 1 < a && graph[tmpX + 1][tmpY][tmpZ] == 0 && !visited[tmpX + 1][tmpY][tmpZ]) {
                visited[tmpX + 1][tmpY][tmpZ] = true;
                point next;
                next.x = tmpX + 1;
                next.y = tmpY;
                next.z = tmpZ;
                next.step = current.step + 1;
                q.push(next);
            }

            if (tmpY - 1 >= 0 && graph[tmpX][tmpY - 1][tmpZ] == 0 && !visited[tmpX][tmpY - 1][tmpZ]) {
                visited[tmpX][tmpY - 1][tmpZ] = true;
                point next;
                next.x = tmpX;
                next.y = tmpY - 1;
                next.z = tmpZ;
                next.step = current.step + 1;
                q.push(next);
            }
            if (tmpY + 1 < b && graph[tmpX][tmpY + 1][tmpZ] == 0 && !visited[tmpX][tmpY + 1][tmpZ]) {
                visited[tmpX][tmpY + 1][tmpZ] = true;
                point next;
                next.x = tmpX;
                next.y = tmpY + 1;
                next.z = tmpZ;
                next.step = current.step + 1;
                q.push(next);
            }

            if (tmpZ - 1 >= 0 && graph[tmpX][tmpY][tmpZ - 1] == 0 && !visited[tmpX][tmpY][tmpZ - 1]) {
                visited[tmpX][tmpY][tmpZ - 1] = true;
                point next;
                next.x = tmpX;
                next.y = tmpY;
                next.z = tmpZ - 1;
                next.step = current.step + 1;
                q.push(next);
            }
            if (tmpZ + 1 < c && graph[tmpX][tmpY][tmpZ + 1] == 0 && !visited[tmpX][tmpY][tmpZ + 1]) {
                visited[tmpX][tmpY][tmpZ + 1] = true;
                point next;
                next.x = tmpX;
                next.y = tmpY;
                next.z = tmpZ + 1;
                next.step = current.step + 1;
                q.push(next);
            }
        }

        if (time < maxValue) cout << time;
        else cout << -1;

        cout << endl;
    }

    return 0;
}