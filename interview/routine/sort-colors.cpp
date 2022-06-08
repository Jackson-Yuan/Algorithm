#include "iostream"
#include "vector"

using namespace std;
/**
 * 给定一个包含红色、白色和蓝色、共n 个元素的数组nums，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 我们使用整数 0、1 和 2 分别表示红色、白色和蓝色。
 * 必须在不使用库的sort函数的情况下解决这个问题。
 * 尝试用一个仅使用常数空间的一趟扫描算法
 * 链接：https://leetcode-cn.com/problems/sort-colors
 * */

/**
 * 本题最简单的做法就是直接用排序
 * 大门题目要求一次遍历解决，注意到我们能排序的元素是固定的，这便为这个要求提供可能
 * 解法其实很简单，利用排序元素是固定的0，1，2，我们一次扫描分别对0，1进行交换即可
 * */
class Solution {
public:
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                ++p1;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }
};

