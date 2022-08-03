#include "iostream"
#include "vector"

using namespace std;

/**
 * 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
 * 链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
 * */

/**
 * 本题最简单粗暴的方法，直接建立hash表完事
 *
 * 如果要求不用额外辅助空间，则具体思路如下：因为n的数组，取值范围为[1,n]，则这些数加上n肯定是大于n。
 * 我们可以遍历每一个数，在其对应索引位置上加n 如元素为4 则在索引为3的位置上加n， 但注意到对应索引位置的元素加上n之后，无法直接根据值得出它的索引位置
 * 但又因为我们是加的n，可以利用模运算（模n）来得到其真实的索引位置（很巧妙）
 *
 * 遍历完后，凡是索引位置元素没大于n的，加一就是缺少的元素
 * */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();
        for (auto &num: nums) {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }

    /**
     * 另外一种不同的解法
     * */
    vector<int> findDisappearedNumbers2(vector<int> &nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i + 1 == nums[i]) continue;
            while (nums[i] != i + 1) {
                if (nums[nums[i] - 1] == nums[i]) break;
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i + 1 != nums[i]) ans.push_back(i + 1);
        }


        return ans;
    }
};

