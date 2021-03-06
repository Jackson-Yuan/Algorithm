/**
 *给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
 * */
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int target = 0 - nums[i];
                int left = i + 1, right = nums.size() - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == target) {
                        res.push_back({nums[i], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    } else if (nums[left] + nums[right] > target) right--;
                    else left++;
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> res = s.threeSum(nums);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}
/**
 * 本来是求三数之和 可以转化为两数之和num[k] + num[j] = -num[i]
 * 遍历i 耗掉一层循环 k，j 因为存在重复元素，无法使用Hash
 * 要么暴力 暴力超时， 用双指针left right， 从一头，一尾开始遍历 把平方级转为线性级
 * 去重操作值得学习 排序是一种手段
 * */