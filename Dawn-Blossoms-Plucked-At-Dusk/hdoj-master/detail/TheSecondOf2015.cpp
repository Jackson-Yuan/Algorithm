/**
 * 2015年第二题
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int>> graph;
vector<vector<bool>> visited;

void dfs(int x, int y, int val) {
    visited[x][y] = true;
    if (x - 1 >= 0 && graph[x - 1][y] == val && !visited[x - 1][y]) dfs(x - 1, y, val);
    if (x + 1 < graph.size() && graph[x + 1][y] == val && !visited[x + 1][y]) dfs(x + 1, y, val);
    if (y - 1 >= 0 && graph[x][y - 1] == val && !visited[x][y - 1]) dfs(x, y - 1, val);
    if (y + 1 < graph[0].size() && graph[x][y + 1] == val && !visited[x][y + 1]) dfs(x, y + 1, val);
}

int main() {
    int m, n;
    cin >> m >> n;
    graph = vector<vector<int>>(m, vector<int>(n, 0));
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j]) {
                ++res;
                dfs(i, j, graph[i][j]);
            }
        }
    }

    cout << res << endl;
    return 0;
}
/**
 * 利用深搜检验连通块
 * */