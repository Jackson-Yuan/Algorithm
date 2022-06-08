#include "iostream"
#include "vector"
#include "string"

using namespace std;

/**
 * 给定一个m x n 二维字符网格board 和一个字符串单词word 。如果word 存在于网格中，返回 true ；否则，返回 false 。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 链接：https://leetcode-cn.com/problems/word-search
 * */

/**
 * 这题唯一要说的一点就是，参数若用来读，尽量使用引用传递
 * 虽然在方法参数上意识到这一点，但在遍历方向数组时
 * 原本auto direct在某些用例下会超时，但变为
 * auto& direct，速度提高 服气
 * */

class Solution {
private:
    vector<vector<int>> directs = {{1,  0},
                                   {-1, 0},
                                   {0,  1},
                                   {0,  -1}};
    bool isFind;
    vector<vector<bool>> visited;
    int row;
    int column;
public:
    bool exist(vector<vector<char>> &board, string word) {
        row = board.size();
        column = board[0].size();
        visited = vector<vector<bool>>(row, vector<bool>(column, false));
        isFind = false;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (!isFind && board[i][j] == word[0]) {
                    dfs(i, j, 1, word, board);
                    if (isFind) break;
                }
            }

            if (isFind) break;
        }

        return isFind;
    }


    void dfs(int x, int y, int index, string &word, vector<vector<char>> &graph) {
        if (index == word.length()) {
            isFind = true;
            return;
        }

        visited[x][y] = true;

        for (auto &direct : directs) {
            if (isFind) break;
            int next_x = x + direct[0];
            int next_y = y + direct[1];

            if (next_x < 0 || next_x >= row || next_y < 0 || next_y >= column) continue;

            if (!isFind && !visited[next_x][next_y] && graph[next_x][next_y] == word[index]) {
                dfs(next_x, next_y, index + 1, word, graph);
            }
        }

        visited[x][y] = false;
    }
};