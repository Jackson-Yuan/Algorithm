/**
 * 给你一个整数数组 nums 和一个整数 k。
 * 如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
 * 请返回这个数组中「优美子数组」的数目。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int numberOfSubArrays(vector<int> &nums, int k) {
        int left = 0, right = 0, res = 0;
        int count = 0;
        while (right < nums.size()) {
            if (nums[right] & 1) {
                ++count;
            }
            if (count == k) {
                /**个数到k，表明现在left 到 right 之间奇数个数满足要求，开始滑动*/
                int tmp = right;
                ++right;
                while (right < nums.size() && (nums[right] & 1) == 0) ++right;/**向右滑动，边界为下一个奇数或到末尾*/
                int rightRes = right - tmp;/**右个数*/
                tmp = left;
                while ((nums[left] & 1) == 0) ++left;/**向右滑动，算出左边有多少个，边界为碰到的第一个奇数，一定能碰到*/
                int leftRes = left - tmp + 1;/**左个数*/
                res += leftRes * rightRes;/**两者相乘即可*/
                ++left;
                --count;
            } else ++right;/**个数没到k 继续后移*/
        }
        return res;
    }
};

int main() {
    vector<int> array = {1, 1, 2, 1, 1};
    Solution solution;
    cout << solution.numberOfSubArrays(array, 3);
}
/**
 * 此题本来是直接暴力，枚举所有字迹统计奇数个数来实现
 * 其实此题利用滑动窗口来实现，尼玛概念一套一套的
 * 核心思路在于维护一个满足k个奇数的滑动窗口，活动窗口所包含的不就是一个子集嘛
 * 然后将此窗口向左或向右滑动，生成不同的子集，核心原则在于窗口内的奇数个数为k
 * 具体流程减代码注释
 * */