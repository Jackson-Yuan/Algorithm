#include "iostream"
#include "stack"
#include "vector"

using namespace std;

/**
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 * 链接:https://leetcode.cn/problems/largest-rectangle-in-histogram/
 * */

/**
 * 此题思路单调栈，对于位置i，寻找当前位置左右两边第一个小于heights[i]的位置，左边的位置+1即为左边离他最远的大于等于heights[i]的位置
 * 右边的位置-1即为右边离他最远大于等于heights[i]的位置，两个位置的距离 * height[i]即为i位置上的面积最大值
 * */
class Solution {
public:
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