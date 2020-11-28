/**
 * 给定一个数组nums，如果i < j且nums[i] > 2*nums[j]我们就将(i, j)称作一个重要翻转对。
 * 你需要返回给定数组中的重要翻转对的数量。
 * */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int reversePairs(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        else return merge(nums, 0, nums.size() - 1);
    }

    int merge(vector<int> &nums, int left, int right) {
        if (left == right) return 0;
        else {
            int mid = (left + right) / 2;
            int leftVal = merge(nums, left, mid);
            int rightVal = merge(nums, mid + 1, right);
            int ret = leftVal + rightVal;

            /**
             * 此处是一个压缩时间复杂度的技巧
             * 你可以在while循环中每次都令y = i + 1，结果不会错，但没有必要
             * 因为归并排序，两边的数组都是有序的，前一个数组最大容纳个数，必定也
             * 会被其后一个容纳，没这个必要从头开始，并且这种做法，一旦数组长度过长
             * 直接超时
             * */
            int i = left, j = mid + 1;
            while (i <= mid) {
                while (j <= right && (long long) nums[i] > 2 * (long long) nums[j]) ++j;
                ret += j - mid - 1;
                ++i;
            }

            vector<int> sorted(right - left + 1);
            i = left;
            j = mid + 1;
            int p = 0;
            while (i <= mid || j <= right) {
                if (i > mid) {
                    sorted[p++] = nums[j++];
                } else if (j > right) {
                    sorted[p++] = nums[i++];
                } else {
                    if (nums[i] <= nums[j]) sorted[p++] = nums[i++];
                    else sorted[p++] = nums[j++];
                }
            }

            for (int i = 0; i < sorted.size(); ++i) {
                nums[left + i] = sorted[i];
            }

            return ret;
        }
    }
};
/**
 * 此处利用的是归并排序中过程的性质
 * 翻转对的要求是i < j且nums[i] > 2*nums[j]
 * 我们不妨利用归并排序过程，在归并排序每趟过程中
 * 一分为二的数组，左边数组每个元素原本的索引（因为在归并中，会被大乱，但总体不影响）
 * 都必然小于右边数组元素原本索引，且都是有序的这就同时能实现翻转对的两个要求
 * 且在归并的全过程中，可以保证每个元素都会被比较到
 * */