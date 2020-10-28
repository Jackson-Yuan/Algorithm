/**
 *  有s毫升的可乐，有m毫升与n毫升的杯子(没有刻度)，问至少要倒多少次，可以平分此可乐
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
bool visited[100][100][100];

void aToB(int &a, int &b, int realA, int realB) {/**A杯想B杯倒水*/
    if (realB - b >= a) {
        b += a;
        a = 0;
    } else {
        a -= realB - b;
        b = realB;
    }
}

struct point {
    int a, b, c;
    int step;
};

int main() {
    int s, m, n;
    while (cin >> s >> m >> n) {
        memset(visited, 0, sizeof(visited));
        point start;
        start.a = s;
        start.b = 0;
        start.c = 0;
        start.step = 0;
        queue<point> q;
        q.push(start);
        visited[start.a][start.b][start.c] = true;
        int res = -1;
        while (!q.empty()) {
            point current = q.front();
            q.pop();
            if (current.a == (double) s / 2 && current.b == (double) s / 2) {
                res = current.step;
                break;
            }
            if (current.a == (double) s / 2 && current.c == (double) s / 2) {
                res = current.step;
                break;
            }
            if (current.c == (double) s / 2 && current.b == (double) s / 2) {
                res = current.step;
                break;
            }

            int a = current.a, b = current.b, c = current.c;
            aToB(a, b, s, m);
            if (!visited[a][b][c]) {
                visited[a][b][c] = true;
                point next;
                next.a = a;
                next.b = b;
                next.c = c;
                next.step = current.step + 1;
                q.push(next);
            }

            a = current.a, b = current.b, c = current.c;
            aToB(a, c, s, n);
            if (!visited[a][b][c]) {
                visited[a][b][c] = true;
                point next;
                next.a = a;
                next.b = b;
                next.c = c;
                next.step = current.step + 1;
                q.push(next);
            }

            a = current.a, b = current.b, c = current.c;
            aToB(b, a, m, s);
            if (!visited[a][b][c]) {
                visited[a][b][c] = true;
                point next;
                next.a = a;
                next.b = b;
                next.c = c;
                next.step = current.step + 1;
                q.push(next);
            }


            a = current.a, b = current.b, c = current.c;
            aToB(b, c, m, n);
            if (!visited[a][b][c]) {
                visited[a][b][c] = true;
                point next;
                next.a = a;
                next.b = b;
                next.c = c;
                next.step = current.step + 1;
                q.push(next);
            }

            a = current.a, b = current.b, c = current.c;
            aToB(c, a, n, s);
            if (!visited[a][b][c]) {
                visited[a][b][c] = true;
                point next;
                next.a = a;
                next.b = b;
                next.c = c;
                next.step = current.step + 1;
                q.push(next);
            }


            a = current.a, b = current.b, c = current.c;
            aToB(c, b, n, m);
            if (!visited[a][b][c]) {
                visited[a][b][c] = true;
                point next;
                next.a = a;
                next.b = b;
                next.c = c;
                next.step = current.step + 1;
                q.push(next);
            }
        }

        cout << res << endl;
    }

    return 0;
}

/**
 * 此题利用bfs，从初始状态S 0 0 分别枚举每个杯子向另外两个杯子倒可乐情况，压入队列，再逐个判断即可
 * */