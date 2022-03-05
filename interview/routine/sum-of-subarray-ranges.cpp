#include "iostream"
#include "vector"
#include "stack"

using namespace std;
/**
 * 给你一个整数数组 nums 。nums 中，子数组的 范围 是子数组中最大元素和最小元素的差值。
 * 返回 nums 中 所有 子数组范围的 和 。
 * 子数组是数组中一个连续 非空 的元素序列。
 * 链接：https://leetcode-cn.com/problems/sum-of-subarray-ranges
 * */

/**
 * 本题第一种方法，直接暴力不多bb
 * 这边说一下o(n)时间复杂度的方法，利用单调栈来解决问题
 * 单调栈就是保持栈内元素是按照递增或者递减顺序保存，若插入
 * 一个元素不满足的话，就疯狂让栈内元素出栈，直到满足条件为止，适用于一维数组寻找第一个满足某种条件的数
 *
 * 这到题目是计算所有连续子数组的最大值与最小值的和
 * 换一钟想法，其实就是每个数成为连续子数组区间最大值次数p与最小值次数q的差值乘本身（p-q）* val
 * 所以难点在于如何确定p与q，假设要确实数组某个元素a（其索引为k）的p与q，因为要求连续子数组，所以只要
 * 寻找以当前元素为出发点，向左右寻找第一个大于a元素的索引，记为i，j 则p的个数为（k - i）*（j - k）
 * q同理，现在唯一要做的就是确定i，j的位置，此时单调栈可以很好地解决这种问题，我们可以从首部遍历来确定
 * i，从尾部遍历确定j（相当于数组倒过来从首部遍历）。以首部遍历确定计算q需要的i为例，维护一个递减的单调栈，当加入一个元素时，若栈顶大于它，则栈顶就是我们
 * 要找到i，若不是，则出栈寻找下一个栈顶。这样就确定了i，也无需担心弹出的元素会影响到后面还未判断元素的判断。因为弹出的元素是因为新
 * 加入了个比它大的元素，后面的元素若大于它，自然而然大于弹出的元素，若比它小，则它就是我们要的第一个元素。
 *
 *
 * 至于为什么是o（n），乍一看不像o（n），但换个思路想，每个元素只入栈一次，至多出栈一次，则其实就是o（n）
 * */
class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        stack<int> minS, maxS;

        vector<int> minLeft(nums.size(), 0);
        vector<int> minRight(nums.size(), 0);

        vector<int> maxLeft(nums.size(), 0);
        vector<int> maxRight(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i) {
            while (!maxS.empty() && nums[maxS.top()] < nums[i]) {
                maxS.pop();
            }
            minLeft[i] = (maxS.empty() ? -1 : maxS.top());
            maxS.push(i);


            while (!minS.empty() && nums[minS.top()] > nums[i]) {
                minS.pop();
            }

            maxLeft[i] = (minS.empty() ? -1 : minS.top());
            minS.push(i);
        }


        while (!minS.empty()) minS.pop();
        while (!maxS.empty()) maxS.pop();
        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!maxS.empty() && nums[maxS.top()] <= nums[i]) {
                maxS.pop();
            }
            minRight[i] = (maxS.empty() ? nums.size() : maxS.top());
            maxS.push(i);


            while (!minS.empty() && nums[minS.top()] >= nums[i]) {
                minS.pop();
            }

            maxRight[i] = (minS.empty() ? nums.size() : minS.top());
            minS.push(i);
        }


        long long sumMax = 0, sumMin = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sumMax += (long long) ((minRight[i] - i) * (i - minLeft[i])) * nums[i];
            sumMin += (long long) ((maxRight[i] - i) * (i - maxLeft[i])) * nums[i];
        }

        return sumMax - sumMin;
    }


};

int main() {
    vector<int> ans = {1, 2, 3};

    Solution solution;

    cout << solution.subArrayRanges(ans);
}