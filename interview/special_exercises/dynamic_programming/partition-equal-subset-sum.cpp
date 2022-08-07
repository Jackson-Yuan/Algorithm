#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
/**
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 连接：https://leetcode.cn/problems/partition-equal-subset-sum/
 * */

/**
 * 利用动态规划，dp[i][j]代表前i个数能否凑成j，状态转移方程，对于当前索引i，若nums[i]小于j，则dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]]
 * 否则dp[i][j] = dp[i-1][j]
 * */

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = 0;
        for (auto val : nums) {
            sum += val;
        }
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};
