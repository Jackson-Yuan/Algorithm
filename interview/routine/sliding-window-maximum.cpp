#include "iostream"
#include "vector"
#include "queue"

using namespace std;


/**
 * 给你一个整数数组 nums，有一个大小为k的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k个数字。滑动窗口每次只向右移动一位。
 * 返回滑动窗口中的最大值。
 * 链接：https://leetcode-cn.com/problems/sliding-window-maximum
 * */

/**
 * 此题，第一个方法可以维护一个大小为k的最大堆
 * 此外这边引入另外一种解法，单调队列（与单调栈区分），它适用于维护区间最值问题
 * 而单调栈适用于维护最近的大小关系
 * */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> q;
        vector<int> ans;

        for (int i = 0; i < k; ++i) {
            /**
             * 这边关系比较要加上等于，即使相等，因为只有k个 要用最新的
             * */
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }

            q.push_back(i);
        }

        ans.push_back(nums[q.front()]);
        for (int i = k; i < nums.size(); ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }

            q.push_back(i);


            while (q.front() <= i - k) {
                q.pop_front();
            }

            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};

