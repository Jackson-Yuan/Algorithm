#include "iostream"
#include "vector"

using namespace std;

/**
 * 给你一个整数数组 nums ，请你找出 nums 子集 按位或 可能得到的 最大值 ，并返回按位或能得到最大值的 不同非空子集的数目 。
 * 如果数组 a 可以由数组 b 删除一些元素（或不删除）得到，则认为数组 a 是数组 b 的一个 子集 。如果选中的元素下标位置不一样，则认为两个子集 不同 。
 * 对数组 a 执行 按位或，结果等于 a[0] OR a[1] OR ... OR a[a.length - 1]（下标从 0 开始）。
 * 链接：https://leetcode-cn.com/problems/count-number-of-maximum-bitwise-or-subsets
 * */

/**
 * 对付这种子集题目，其实就是对每个元素选与不选两条路，可以利用dfs回溯来做
 *
 * 这边提供一个以循环方式来做的思路
 *
 * 如果有n个元素，每个元素选与不选 共2的n次方，我们可以用一个长度为n的二进制数，0，1代表
 * 对对应位置元素的取舍
 * */
class Solution {
public:
    int countMaxOrSubsets(vector<int> &nums) {
        int n = nums.size(), maxValue = 0, cnt = 0, stateNumber = 1 << n;
        for (int i = 0; i < stateNumber; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    cur |= nums[j];
                }
            }
            if (cur == maxValue) {
                cnt++;
            } else if (cur > maxValue) {
                maxValue = cur;
                cnt = 1;
            }
        }
        return cnt;
    }
};


int main() {
    vector<int> nums = {3, 2, 1, 5};

    Solution solution;
    cout << solution.countMaxOrSubsets(nums);
}

