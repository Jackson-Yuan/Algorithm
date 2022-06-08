#include "iostream"
#include "vector"
#include "queue"

using namespace std;


/**
 * 你现在手里有一份大小为n x n的 网格 grid，上面的每个 单元格 都用0和1标记好了。其中0代表海洋，1代表陆地
 * 请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的，并返回该距离。如果网格上只有陆地或者海洋，请返回-1。
 * 我们这里说的距离是「曼哈顿距离」（Manhattan Distance）：(x0, y0) 和(x1, y1)这两个单元格之间的距离是|x0 - x1| + |y0 - y1|。
 * 链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible
 * */

/**
 * 此题是多源BFS一道典型例题，多源BFS可以视为有多个起点，开始广度优先搜索
 * 其实可以假设有一个超级源点，这个源点只与多个起点链接，问题就等价为
 * 从超级源点开始广搜来解决问题
 * */
struct node {
    int x;
    int y;
    int step;
};

class Solution {
private:
    vector<vector<int>> directs = {{1,  0},
                                   {-1, 0},
                                   {0,  1},
                                   {0,  -1}};
public:
    int maxDistance(vector<vector<int>> &grid) {
        int row = grid.size(), column = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        queue<node> q;

        int ans = -1;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (grid[i][j] == 1) {
                    node cur;
                    cur.x = i;
                    cur.y = j;
                    cur.step = 0;
                    q.push(cur);
                }
            }
        }

        while (!q.empty()) {
            node cur = q.front();
            q.pop();
            if (cur.step > ans) ans = cur.step;
            for (auto &direct : directs) {
                int next_x = cur.x + direct[0];
                int next_y = cur.y + direct[1];

                if (next_x < 0 || next_x >= row || next_y < 0 | next_y >= column) continue;

                if (!visited[next_x][next_y] && grid[next_x][next_y] == 0) {
                    visited[next_x][next_y] = true;
                    node next;
                    next.x = next_x;
                    next.y = next_y;
                    next.step = cur.step + 1;
                    q.push(next);
                }
            }
        }

        if (ans <= 0) return -1;
        else return ans;
    }
};

