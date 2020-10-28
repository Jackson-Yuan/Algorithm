/**
 * 填数独
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct point {
    int x;
    int y;
};
vector<point> points;
char graph[9][9];
bool isStop;

bool check(int x, int y, char val) {
    for (int i = 0; i < 9; ++i) {
        if (i != y && graph[x][i] == val) return false;
    }

    for (int i = 0; i < 9; ++i) {
        if (i != x && graph[i][y] == val) return false;
    }

    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;
    for (int i = startX; i < startX + 3; ++i) {
        for (int j = startY; j < startY + 3; ++j) {
            if (i != x && j != y && graph[i][j] == val) return false;
        }
    }
    return true;
}

void dfs(int index) {
    if (index == (int) points.size()) {
        isStop = true;
        return;
    }
    int x = points[index].x, y = points[index].y;
    for (int i = 1; i <= 9; ++i) {
        if (!isStop && check(x, y, '0' + i)) {
            graph[x][y] = '0' + i;
            dfs(index + 1);
        }
    }
    if (!isStop) graph[x][y] = '?';
}

int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == '?') {
                point cur;
                cur.x = i;
                cur.y = j;
                points.push_back(cur);
            }
        }
    }

    isStop = false;
    dfs(0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << graph[i][j];
            if (j != 8) cout << " ";
        }
        cout << endl;
    }
    return 0;
}