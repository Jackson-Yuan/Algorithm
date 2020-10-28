
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
int maxValue;
vector<vector<char>> base, target;

bool judge(int x, int y) {
    for (int i = 0; i < target.size(); ++i) {
        for (int j = 0; j < target[i].size(); ++j) {
            if (base[x + i][y + j] != target[i][j]) return false;
        }
    }
    return true;
}

void dfs(int x, int y, int count) {
    if (count > maxValue) maxValue = count;

    if (y + target[0].size() - 1 >= base[0].size()) return;
    if (x + target.size() - 1 >= base.size()) return;

    /**如果匹配，试探两个*/
    if (judge(x, y)) {
        dfs(x, y + target[0].size(), count + 1);
        dfs(x + target.size(), y, count + 1);
    }
    /**无论是否匹配，下面两个都要试探*/
    dfs(x, y + 1, count);
    dfs(x + 1, y, count);

}

int main() {
    int M, N, m, n;
    cin >> M >> N;
    getchar();
    base = vector<vector<char>>(M, vector<char>(N, ' '));
    for (int i = 0; i < base.size(); ++i) {
        for (int j = 0; j < base[i].size(); ++j) {
            cin >> base[i][j];
            getchar();
        }
    }

    cin >> m >> n;
    getchar();
    target = vector<vector<char>>(m, vector<char>(n, ' '));
    for (int i = 0; i < target.size(); ++i) {
        for (int j = 0; j < target[0].size(); ++j) {
            cin >> target[i][j];
            getchar();
        }
    }

    maxValue = 0;
    for (int i = 0; i <= base.size() - target.size(); ++i) {
        for (int j = 0; j <= base[0].size() - target[0].size(); ++j) {
            dfs(i, j, 0);
        }
    }

    cout << maxValue << endl;

    return 0;
}
/**
 * 此题就是暴力dfs枚举
 * 当然枚举的形式是外枚举加内枚举
 * 外枚举通过循环来确定起点的坐标
 * 内枚举就是dfs内部以起点开始所试探的几个方向
 * 本想一个dfs把所有情况全部枚举掉但那样不太好写
 * 不如这种写法简单直观
 *
 * 而在求全排列时，是典型的的一个dfs调用直接枚举完
 * 所以用搜索暴力时如何枚举也是要考虑的
 * */