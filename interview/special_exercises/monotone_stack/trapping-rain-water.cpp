#include "iostream"
#include "vector"
#include "stack"
#include "algorithm"

using namespace std;
/**
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 链接：https://leetcode-cn.com/problems/trapping-rain-water/
 * */

/**
 * 本题第一个解法：动态规划，分别算出每跟柱子向左，向右的比本身大的最大高度，二者取其小，得出单根柱子能承载多少雨水，随后累加即可
 *
 * 第二个解法：单调栈(这东西确实用可以用单调栈做，但思路就离谱)
 * 维护一个递减的单调栈（栈内元素递减），从左往右遍历数组，遍历当前元素时
 * 若大于栈顶元素，并且栈内元素至少两个，则栈顶元素的下一个元素（记为extra）必然大于栈顶（extra>top && i > top,必然有一个洼地，可计算雨水量）
 * 相比动态规划法只计算单个，单调栈会计算一批，但能单调栈做法很难想到
 * */
class Solution {
public:
    int trap(vector<int> &height) {
        vector<int> leftMax(height.size(), height[0]);
        vector<int> rightMax(height.size(), height[height.size() - 1]);

        for (int i = 1; i < height.size(); ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        for (int i = height.size() - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }


        int ans = 0;

        for (int i = 0; i < height.size(); ++i) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;
    }

    int trap2(vector<int> &height) {
        stack<int> s;

        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int top = s.top();
                s.pop();
                if (s.empty()) break;

                int extra = s.top();
                int width = i - extra - 1;
                int heightVal = min(height[extra], height[i]) - height[top];
                ans += heightVal * width;
            }

            s.push(i);
        }

        return ans;
    }
};
