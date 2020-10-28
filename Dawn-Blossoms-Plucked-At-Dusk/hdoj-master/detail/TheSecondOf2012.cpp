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
vector<point> path;

bool isMeet(int x, int y) {
    for (int i = 1; i < path.size(); ++i) {
        if (path[i].x == x && path[i].y == y) return true;
    }

    return false;
}

int main() {
    string s;
    while (cin >> s) {
        path.clear();
        for (int i = 11; i <= 30; ++i) {
            point current;
            current.x = 25;
            current.y = i;
            path.push_back(current);
        }
        reverse(path.begin(), path.end());

        int count = 0;
        int token = 0;
        for (int i = 0; i < s.length(); ++i) {
            ++count;
            point pre = path[0];
            for (int j = 1; j < path.size(); ++j) {
                point tmp = path[j];
                path[j] = pre;
                pre = tmp;
            }
            int x = path[0].x, y = path[0].y;
            if (s[i] == 'N') {
                if (x - 1 < 1) {
                    token = 1;
                    break;
                }
                if (isMeet(x - 1, y)) {
                    token = 2;
                    break;
                }

                path[0].x = x - 1;
                path[0].y = y;
            } else if (s[i] == 'S') {
                if (x + 1 > 50) {
                    token = 1;
                    break;
                }
                if (isMeet(x + 1, y)) {
                    token = 2;
                    break;
                }

                path[0].x = x + 1;
                path[0].y = y;
            } else if (s[i] == 'W') {
                if (y - 1 < 1) {
                    token = 1;
                    break;
                }

                if (isMeet(x, y - 1)) {
                    token = 2;
                    break;
                }

                path[0].x = x;
                path[0].y = y - 1;
            } else {
                if (y + 1 > 50) {
                    token = 1;
                    break;
                }

                if (isMeet(x, y + 1)) {
                    token = 2;
                    break;
                }

                path[0].x = x;
                path[0].y = y + 1;
            }
        }

        if (token == 0) {
            cout << "success, " << count << endl;
        } else if (token == 1) cout << "wall, " << count << endl;
        else cout << "body, " << count << endl;
    }

    return 0;
}
/**
 * 贪吃蛇判断是否撞墙还是撞自己身体还是成功
 * 之前考虑复杂,其实就是简单的模拟
 * */