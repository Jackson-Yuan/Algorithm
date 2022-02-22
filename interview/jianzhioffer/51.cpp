#include "iostream"
#include "vector"

using namespace std;


/**
 * 利用归并排序思路解决逆序对
 * */
class Solution {
private:
    vector<int> tmp;
public:
    int reversePairs(vector<int> &nums) {
        if (nums.size() < 2) return 0;
        tmp = vector<int>(nums.size());
        return reversePairs(nums, 0, nums.size() - 1);
    }

    int reversePairs(vector<int> &nums, int left, int right) {
        if (left == right) return 0;
        int mid = left + (right - left) / 2;

        int leftCount = reversePairs(nums, left, mid);
        int rightCount = reversePairs(nums, mid + 1, right);

        int midCount = mergeCount(nums, left, right, mid);

        return leftCount + rightCount + midCount;
    }

    int mergeCount(vector<int> &nums, int left, int right, int mid) {
        for (int i = left; i <= right; ++i) {
            tmp[i] = nums[i];
        }
        int count = 0;
        int i = left, j = mid + 1;
        for (int k = left; k <= right; ++k) {
            if (i == mid + 1) {
                nums[k] = tmp[j];
                ++j;
            } else if (j == right + 1) {
                nums[k] = tmp[i];
                ++i;
            } else if (tmp[j] < tmp[i]) {
                nums[k] = tmp[j];
                ++j;
                count += mid - i + 1;
            } else {
                nums[k] = tmp[i];
                ++i;
            }
        }

        return count;
    }
};

