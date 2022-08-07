#include "iostream"
#include "vector"
#include "stack"

using namespace std;
/**
 * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 链接：https://leetcode.cn/problems/maximal-rectangle/
 * */

/**
 * 本题思路是将输入而二维矩阵每一行及其上面的行视作一个柱状图，题目直接转换成求柱状图的最大矩形面积
 * */
class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);

        int ans = INT_MIN;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                } else height[j] = 0;
            }

            ans = max(ans, largestRectangleArea(height));

        }

        return ans;
    }

    int largestRectangleArea(vector<int> &heights) {
        vector<int> left(heights.size(), -1);
        vector<int> right(heights.size(), -1);

        stack<int> s;

        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if (!s.empty()) left[i] = s.top() + 1;
            else left[i] = 0;

            s.push(i);
        }


        while (!s.empty()) s.pop();
        for (int i = heights.size() - 1; i >= 0; --i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if (!s.empty()) right[i] = s.top() - 1;
            else right[i] = heights.size() - 1;

            s.push(i);
        }


        int ans = INT_MIN;

        for (int i = 0; i < heights.size(); ++i) {
            int width = right[i] - left[i] + 1;
            ans = max(ans, heights[i] * width);
        }

        return ans;
    }
};