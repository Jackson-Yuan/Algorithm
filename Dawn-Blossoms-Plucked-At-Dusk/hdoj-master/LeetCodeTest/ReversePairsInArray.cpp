/**
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
private:
    vector<int> tmp;
public:
    int reversePairs(vector<int> &nums) {
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
/**
 * 利用归并思想巧妙求逆序对 给爷整佛了
 * 核心思想：
 * 在归并排序归并时左边 2 4 6 8 10  右边 1 3 5 7 8
 * 当右边的数要放进原数组时，此时左边剩余的个数就为1的逆序对个数直接加
 * 自底向上归并时，不断累加，最后即为真确答案
 * */