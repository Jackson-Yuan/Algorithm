/**
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 必须原地修改，只允许使用额外常数空间。
 * */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        if (i >= 0) {
            int j = nums.size() - 1;
            while (j > i && nums[i] >= nums[j]) --j;
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
/**
 * 找规律题，不多bb
 * 说一下两个nums数组大于等于
 * 第一个大于等于，若去除等于号，如[5,1,1]这个数组，预期是[1,1,5]，但实际却是[1,5,1]
 * 第二个大于等于，若去除等号，如[1,5,1]这个数组，预期是[5,1,1]，但实际是[1,1,5]
 * 注意！！！
 * */