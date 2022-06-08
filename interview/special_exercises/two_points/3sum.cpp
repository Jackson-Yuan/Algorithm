#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
/**
 * 给你一个包含 n 个整数的数组nums，判断nums中是否存在三个元素 a，b，c ，使得a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 * 链接：https://leetcode-cn.com/problems/3sum
 * */

/**
 * 排序
 * 三个元素，枚举第一个元素(o(n))，剩余两个元素直接双指针寻找(o(n))
 *
 * 着重注意去重的一些操作
 *
 * 四数之和同理，分别枚举第一、二两个元素(o(n^2))，剩余两个直接双指针寻找(o(n))
 * */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;

        if (nums.size() < 3) return ans;

        sort(nums.begin(), nums.end());


        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) return ans;

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    vector<int> cur = {nums[i], nums[left], nums[right]};
                    ans.push_back(cur);
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    if (right <= left) break;
                    ++left;
                    --right;
                } else if (nums[i] + nums[left] + nums[right] > 0) {
                    --right;
                } else {
                    ++left;
                }
            }
        }

        return ans;
    }
};

