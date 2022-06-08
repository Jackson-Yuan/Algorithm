#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/**
 * 整数数组的一个 排列就是将其所有成员以序列或线性顺序排列。
 * 例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
 * 整数数组的下一个排列是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
 * 那么数组的下一个排列就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
 * 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
 * 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
 * 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
 * 给你一个整数数组 nums ，找出 nums 的下一个排列。
 * 必须 原地 修改，只允许使用额外常数空间。
 * 链接：https://leetcode-cn.com/problems/next-permutation
 * */

/**
 * 全排里中当前排列的下一个排列
 * 思路咋说呢，就是找到比当前排列要大（但又不是那么大的排列）
 * 所以说我们要在左边找一个【较小数】，右边找一个【较大数】（并不是单纯意义上的最小数与最大数）
 * 同时我们要让这个【较小数】尽量靠右，而【较大数】尽可能小。当交换完成后，
 * 【较大数】右边的数需要按照升序重新排列。这样可以在保证新排列大于原来排列的情况下，使变大的幅度尽可能小。
 * 如排列【4，5，2，6，3，1】，【2，3】为满足条件的较小数与较大数
 *
 * 至于为啥要像算法中那么做，我只能说这么做确实合理，但怎么想到的，我无法想到
 * 只能说第一个while找到较小数，利用较小数找到较大数
 * 记吧！
 * */
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};