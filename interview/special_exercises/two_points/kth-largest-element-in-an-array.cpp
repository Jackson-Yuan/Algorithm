#include "iostream"
#include "vector"

using namespace std;
/**
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k个不同的元素。
 * */

/**
 * 本题是寻找一个数组中第k个最大元素
 * 一般这种寻找第k个最大或最小元素，最无脑的一种作法是直接排序，然后按照索引取即可，但一般时间复杂度为o（nlogn）
 *
 * 这边介绍一个o（n）算法，本质是利用划分快排的划分函数
 * 我们知道快排的划分函数，一次可以确定一个数的最终位置，这与我们寻找第k个元素想法一致（我们只是要找第
 * k个元素，前k-1个是否有序我不关心，只要能保证前k-1个满足大小关系即可）
 * 我们可以利用这个配合二分来进行寻找，在快排里每次划分后，都要向两边递归，在这里只要向一边递归即可
 *
 * 在划分时，引入随机加速步骤，防止算法退化成平方时间复杂度（每次选取如果都不能一分为二，那么就要划分n次，每次处理时间是o（n））
 *
 * 至于为什么平均是o（n），现在记住就完了，算法导论9.2有推导，反正我现在没看懂
 * */
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int split = partion(start, end, nums);
            if (split == k - 1) return nums[split];
            else if (split > k - 1) end = split - 1;
            else {
                start = split + 1;
            }
        }

        return -1;
    }


    int partion(int start, int end, vector<int> &nums) {
        int randomIndex = rand() % (end - start + 1) + start;
        swap(nums[start], nums[randomIndex]);
        int compare = nums[start];

        while (start < end) {
            while (start < end && nums[end] <= compare) --end;
            nums[start] = nums[end];

            while (start < end && nums[start] >= compare) ++start;
            nums[end] = nums[start];
        }

        nums[start] = compare;
        return start;
    }
};

