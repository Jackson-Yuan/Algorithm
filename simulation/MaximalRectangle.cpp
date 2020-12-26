/**
 * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        /**统计第i行第j列左边连续1的个数（包括其本身）*/
        vector<vector<int>> count(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int start = j, tmp = 0;
                while (start >= 0 && matrix[i][start] == '1') {
                    ++tmp;
                    --start;
                }
                count[i][j] = tmp;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (count[i][j] == 0) continue;
                int start = i, height = 0, width = count[i][j];
                while (start >= 0 && count[start][j]) {
                    ++height;
                    /**向上枚举，随着高增大，宽要选取最小的来满足所有人的要求*/
                    width = min(width, count[start][j]);
                    int area = height * width;
                    ans = max(ans, area);
                    --start;
                }
            }
        }

        return ans;
    }
};
/**
 * 此题思路，先开一个二维数组存储第i行第j列左边连续1的个数（包括其本身）
 * 然后将第i行第j列当作每个矩形的右下角，
 * 然后依次枚举i，i-1，... , 0行第j列所组合的矩形面积选最大即可
 * */