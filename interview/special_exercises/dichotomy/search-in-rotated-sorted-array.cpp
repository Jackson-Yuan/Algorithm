#include "iostream"
#include "vector"

using namespace std;

/**
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了旋转，
 * 使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
 * 例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为[4,5,6,7,0,1,2] 。
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回-1。
 * 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
 * */

/**
 * 本题是二分+旋转数组，一般旋转数组需要利用第一个元素和最后一个元素与mid值比较
 * 以确定位于哪个有序区间(判定条件值得注意)，在不同的有序区间有不同的二分策略
 *
 * 比如这题
 * 若mid落在在前半部分的有序区间，若target大于mid值，则没什么好说的 目标值只能位于mid值右边（道理很简单，旋转后，数组的最大值只能位于前半部分
 * 的有序区间（升序情况下），你比mid还大，那只能在mid右边）；若小于mid值，则要分两种情况，若比数组第一个位置上元素还小，那肯定在后板部分的有序区间
 * 为了配合二分，则肯定位于mid右边，若在mid值与第一个元素间，在mid值左边
 *
 * 若mid落在后半部分有序区间，若target小于mid值，则肯定位于mid左边（道理很简单，旋转后，数组的最小值只能位于后半部分
 * 的有序区间（升序情况下），你比mid还小，那只能在mid左边）；若大于mid值，则要分两种情况，若比数组最后一个位置上元素要小，则target肯定
 * 位于这个区间内，即mid值右边，若大则只可能位于前半部分有序区间，为了配合二分，则肯定位于mid左边
 *
 * */
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;

        int leftVal = nums[left], rightVal = nums[right];

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;

            if (leftVal <= nums[mid]) {
                if (target > nums[mid]) left = mid + 1;
                else if (target >= leftVal) right = mid - 1;
                else left = mid + 1;
            } else {
                if (target < nums[mid]) right = mid - 1;
                else if (target <= rightVal) left = mid + 1;
                else right = mid - 1;
            }
        }

        return -1;
    }
};
