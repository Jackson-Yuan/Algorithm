#include "iostream"
#include "vector"

using namespace std;

/**
 * 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
 * 请你找出并返回只出现一次的那个数。
 * 你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
 * */

/**
 * 这种只有一个数是奇数，其他数都是偶数的数 有一个通用的解法，那就是直接把所有元素进行异或运算
 * 偶数个的数异或之后全为0，那么剩余那个奇数个的数异或之后必定是那个值
 *
 *
 * 但此题额外加了个条件，即排序，使得logn复杂度成为可能。
 * 注意观察，只出现一次的数，两边必然都是偶数个数的有序排列，且因为排序，相同的数都靠在一起
 * 在左边，若num[x]=nums[x+1],则x必为偶数，在右边，nums[x]=nums[x+1].则x必为奇数
 * 这是进行二分往哪个方向压缩的重要条件。我们可以在二分时对mid值得奇偶性进行判断
 * 若为偶看他下一个，若为奇看他前一天，若相等，则代表这对数在单一数在mid位置的右边，则left=mid+1
 * 若不等，则代表单一数在mid位置的右边，贼right=mid，为什么不是mid-1，因为不等不仅因为是单一数右边的特征
 * 还有可能就是单一数本身
 * */
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            int a = nums[mid];
            int b;
            if (mid % 2 == 0) {
                if (mid + 1 < nums.size()) b = nums[mid + 1];
                else b = nums[mid];
            } else {
                if (mid - 1 >= 0) b = nums[mid - 1];
                else b = nums[mid];
            }
            if (a == b) {
                left = mid + 1;
            } else right = mid;
        }

        return nums[left];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 3, 3};

    cout << solution.singleNonDuplicate(nums);
}
