#include "iostream"
#include "vector"

using namespace std;
/**
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
 * 链接：https://leetcode.cn/problems/maximal-square/
 * */

/**
 * dp数组的含义代表，以i，j为右下角的正方形的边长
 * 状态转移方程，dp[i][j]来自于min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])，左边和上边好理解，斜上方主要保证正方形是实心的非空心的
 * */
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == '1') dp[0][i] = 1;
            ans = max(ans, dp[0][i]);
        }


        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    int up = 0, left = 0, shift = 0;
                    up = dp[i - 1][j];
                    if (j - 1 >= 0) {
                        left = dp[i][j - 1];
                        shift = dp[i - 1][j - 1];
                    }

                    dp[i][j] = min(up, min(left, shift)) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }

        }

        return ans * ans;
    }
};

