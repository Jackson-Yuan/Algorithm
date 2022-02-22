#include "iostream"
#include "vector"

using namespace std;

/**
 * 在一个n x n的国际象棋棋盘上，一个骑士从单元格 (row, column)开始，并尝试进行 k 次移动。行和列是 从 0 开始 的，所以左上单元格是 (0,0) ，右下单元格是 (n - 1, n - 1) 。
 * 象棋骑士有8种可能的走法，如下图所示。每次移动在基本方向上是两个单元格，然后在正交方向上是一个单元格。
 * 每次骑士要移动时，它都会随机从8种可能的移动中选择一种(即使棋子会离开棋盘)，然后移动到那里。
 * 骑士继续移动，直到它走了 k 步或离开了棋盘。
 * 返回 骑士在棋盘停止移动后仍留在棋盘上的概率 。
 * 链接：https://leetcode-cn.com/problems/knight-probability-in-chessboard
 * */

/**
 * 无脑暴力dfs即可
 * 但这题需要进行一定的记忆化搜索措施，因为每向前一步都有可能走回来，所以导致递归深度很大
 * 进行记忆化递归可以减小运算量
 * 同时注意，因为保存的是double类型，判断是否保存的条件不是是否等于0，而是大于一个很小的数
 *
 * 但此题应该不需要，但为了养成习惯，还是写上
 * */
class Solution {
public:
    //八个方向
    vector<pair<int, int>> directions = {{1,  2},
                                         {-1, 2},
                                         {1,  -2},
                                         {-1, -2},
                                         {2,  1},
                                         {-2, 1},
                                         {2,  -1},
                                         {-2, -1}};

    double knightProbability(int N, int K, int r, int c) {
        //board[row][col][j]用于存储在row行，col列走j步不出界的概率
        vector<vector<vector<double>>> board(N, vector<vector<double>>(N, vector<double>(K + 1, 0)));
        return nextStep(board, N, K, r, c, K);
    }

    //step代表的是还需要走的步数，[nowRow][nowCol]是现在的位置
    double nextStep(vector<vector<vector<double>>> &board, int N, int K, int nowRow, int nowCol, int step) {
        if (nowRow < 0 || nowCol < 0 || nowRow >= N || nowCol >= N) {//出界
            return 0;
        }
        //如果此时step == 0，代表它已经不能移动，所以没有出界的概率就是1.0
        if (step == 0) {
            return 1.0;
        }
        //如果这个点之前搜索过，（注意double类型不能直接判断board[nowRow][nowCol][step] == 0，需要判断它是否小于一个很小的值，比如1e-6）
        if (abs(board[nowRow][nowCol][step]) > 1e-6) {
            return board[nowRow][nowCol][step];
        }
        //穷举八个方向
        for (auto &direction : directions) {
            board[nowRow][nowCol][step] +=
                    nextStep(board, N, K, nowRow + direction.first, nowCol + direction.second, step - 1) / 8;
        }
        return board[nowRow][nowCol][step];
    }
};

int main() {
    Solution solution;
    cout << solution.knightProbability(3, 2, 0, 0);

    double a = 0.000000000000000000000007;
    double b = 0.000000000000000000000006;

    cout << (a == b);
}

