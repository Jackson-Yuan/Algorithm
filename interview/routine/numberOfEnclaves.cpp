#include "iostream"
#include "vector"

using namespace std;

/**
 *给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。
 * 一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。
 * 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
 * */
class Solution {
private:
    vector<vector<int>> graph;
    vector<vector<bool>> visited;
    vector<vector<int>> directs = {{1,  0},
                                   {-1, 0},
                                   {0,  1},
                                   {0,  -1}};
public:
    int numEnclaves(vector<vector<int>> &grid) {
        graph = grid;
        int m = graph.size(), n = graph[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            if (graph[i][0] == 1 && !visited[i][0]) dfs(i, 0);
            if (graph[i][n - 1] == 1 && !visited[i][n - 1]) dfs(i, n - 1);
        }

        for (int i = 0; i < n; ++i) {
            if (graph[0][i] == 1 && !visited[0][i]) dfs(0, i);
            if (graph[m - 1][i] == 1 && !visited[m - 1][i]) dfs(m - 1, i);
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][j] == 1 && !visited[i][j]) ++ans;
            }
        }

        return ans;
    }

    void dfs(int x, int y) {
        visited[x][y] = true;

        for (auto direct : directs) {
            int next_x = x + direct[0];
            int next_y = y + direct[1];
            if (!(next_x >= 0 && next_x < graph.size() && next_y >= 0 && next_y < graph[0].size())) continue;

            if (!visited[next_x][next_y] && graph[next_x][next_y] == 1) {
                dfs(next_x, next_y);
            }
        }
    }
};

/**
 * 此题最初想法是直接暴力每个grid为1的点进行dfs看是否触及边界
 * 其实大可不必，可以直接选取边界上为1的点，进行dfs，这样凡是不能够
 * 触及边界的grid为1的点都不会被访问到
 * */