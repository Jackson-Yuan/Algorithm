/**
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * leetcode 42
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!s.empty() && height[s.top()] < height[i]) {
                int cur = s.top();
                s.pop();
                while (!s.empty() && height[s.top()] == height[cur]) s.pop();

                if (!s.empty()) {
                    ans += (min(height[s.top()], height[i]) - height[cur]) * (i - s.top() - 1);
                }
            }

            s.push(i);
        }
        return ans;
    }
};
/**
 * 单调栈的应用，所谓单调栈就是除了本身是个栈之外，还得保持栈内元素单调
 * 此题的解法正是利用单调栈办事
 * 思路是逐一将各个高度压入栈中，因要能积水所以这个单调栈要保持单调不增，因为只有这样保持
 * 才能使当下一个高度准备压栈时，弹出比他矮的才能进行积水
 * 弹出比他矮的高度中有个去重操作，因单调不增，所以栈顶难免由重复，所以弹出一个高度，要弹出所有跟他一样的高度
 * 然后将此时栈顶高度与要压入栈的高度，看哪个小，小的减去弹出的高度 再 乘以 栈顶高度所处的位置与压入栈的高度所处的位置之间的宽即可
 * */