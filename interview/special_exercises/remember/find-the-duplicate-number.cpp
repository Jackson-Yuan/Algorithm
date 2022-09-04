#include "iostream"
#include "vector"

using namespace std;
/**
 * 给定一个包含n + 1 个整数的数组nums ，其数字都在[1, n]范围内（包括 1 和 n），可知至少存在一个重复的整数。
 * 假设 nums 只有 一个重复的整数 ，返回这个重复的数 。
 * 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
 * 链接：https://leetcode.cn/problems/find-the-duplicate-number
 * */

/**
 * 本题无法多说什么，直接记解法，将其转化为环形链表找相交点（且根据题目条件，这个必成环）
 *
 * 如数组[1, 3, 4, 2]
 * 则可转换链表0->1 1->3, 3->2, 2->4, 4->越界（null）
 *
 * 又如数组[1, 3, 4, 2, 2]
 * 可转换链表：0->1, 1->3, 3->2, 2->4, 4->2 (开始成环)
 * */
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    Solution solution;
    cout << solution.findDuplicate(nums);
}

