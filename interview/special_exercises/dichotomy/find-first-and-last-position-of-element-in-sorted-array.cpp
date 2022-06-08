#include "iostream"
#include "vector"

using namespace std;
/**
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 如果数组中不存在目标值 target，返回[-1, -1]。
 * 进阶：
 * 你可以设计并实现时间复杂度为O(log n)的算法解决此问题吗？
 * 链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
 * */

/**
 * 看到有序 + 查找，再看到logn 直接二分法安排
 * 但要找出第一次和最后一次出现的位置
 * 分别用二分法来查找（当然也可以利用常规的二分找到一个，然后向两边扩散）
 *
 * 在查找第一次出现的位置时（即最左边），判定条件要把nums[mid]>=target，等号加上，这样在找到第一个值为target时，依然可以保证向左
 * 移动，且通过一个ans变量来存储mid索引（可以通过ans来判端对应索引上是否为target）
 *
 * 查找最后一次出现位置（即最右边），判定条件nums[mid]<=target，等号要加上，这样在找到第一个值为target时，依然可以保证向右移，
 * 且通过一个ans变量来存储mid索引（可以通过ans来判端对应索引上是否为target）
 *
 * 下面的代码做了两者的合并，导致在判断最后一次出现位置时，真正的ans需要额外减1
 *
 * 同时也补上了分开查找的代码binarySearchLeft、binarySearchRight  
 * */
class Solution {
public:
    int binarySearch(vector<int> &nums, int target, bool lower) {
        int left = 0, right = (int) nums.size() - 1, ans = (int) nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int binarySearchLeft(vector<int> &nums, int target) {
        int left = 0, right = (int) nums.size() - 1, ans = (int) nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int binarySearchRight(vector<int> &nums, int target) {
        int left = 0, right = (int) nums.size() - 1, ans = (int) nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        }
        return vector<int>{-1, -1};
    }
};

