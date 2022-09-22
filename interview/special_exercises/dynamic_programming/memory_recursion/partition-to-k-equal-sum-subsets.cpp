#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
/**
 * 给定一个整数数组 nums和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
 * */

/**
 * 本质dfs暴力破解之，对于nums中每一个数，都有k个子集选择，dfs暴力就行
 * 但需要涉及必要的剪枝操作，否则超时，首先是每个子集之和要若是大于上界，就不要在往里面塞了（为了提高这步剪枝的命中率，优先往里面塞大元素）
 * 第二个剪枝比较叼，是判断当前选择加入的子集与前一个子集是否相等，如果相等就别加入了，因为两个子集无论放进哪一个，最终效果都一样
 * */

class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (sum % k != 0) return false;
        int target = sum / k;
        sort(nums.begin(), nums.end());
        /**
         * 从大到小排，提高剪枝二的命中率，加不加这一步，时间影响很大
         * */
        reverse(nums.begin(), nums.end());
        vector<int> bucket(k, 0);
        return backtrack(nums, 0, bucket, k, target);

    }

    bool backtrack(vector<int> &nums, int index, vector<int> &bucket, int k, int target) {
        // 结束条件优化
        if (index == nums.size()) return true;
        for (int i = 0; i < k; i++) {
            // 剪枝一 影响也很大
            if (i > 0 && bucket[i] == bucket[i - 1]) continue;
            // 剪枝二
            if (bucket[i] + nums[index] > target) continue;
            bucket[i] += nums[index];
            if (backtrack(nums, index + 1, bucket, k, target)) return true;
            bucket[i] -= nums[index];
        }
        return false;
    }
};