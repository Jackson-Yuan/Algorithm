#include "iostream"
#include "vector"
#include "string"

using namespace std;

/**
 * ����һ��m x n ��ά�ַ�����board ��һ���ַ�������word �����word �����������У����� true �����򣬷��� false ��
 * ���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�
 * ���ӣ�https://leetcode-cn.com/problems/word-search
 * */

/**
 * ����ΨһҪ˵��һ����ǣ�������������������ʹ�����ô���
 * ��Ȼ�ڷ�����������ʶ����һ�㣬���ڱ�����������ʱ
 * ԭ��auto direct��ĳЩ�����»ᳬʱ������Ϊ
 * auto& direct���ٶ���� ����
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