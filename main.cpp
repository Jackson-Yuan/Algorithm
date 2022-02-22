#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include "set"
#include "stack"

using namespace std;

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
        for (int i = m; i < m; ++i) {
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

int main() {
    Solution solution;
    vector<vector<int>> grid = {{0, 0, 0, 0},
                                {1, 0, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0}};
    cout << solution.numEnclaves(grid);
}