/**
 * 给定一个整数数组nums，返回区间和在[lower, upper]之间的个数，包含lowe和upper。
区间和S(i, j)表示在nums中，位置从i到j的元素之和，包含i和j(i ≤ j)。

说明:
最直观的算法复杂度是O(n2) ，请在此基础上优化你的算法。
 * */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int countRangeSumRecursive(vector<int> &sum, int lower, int upper, int left, int right) {
        if (left == right) {
            return 0;
        } else {
            int mid = (left + right) / 2;
            int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
            int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
            int ret = n1 + n2;

            // 首先统计下标对的数量
            int i = left;
            int l = mid + 1;
            int r = mid + 1;
            while (i <= mid) {
                while (l <= right && sum[l] - sum[i] < lower) l++;
                while (r <= right && sum[r] - sum[i] <= upper) r++;
                ret += (r - l);
                i++;
            }

            // 随后合并两个排序数组
            vector<int> sorted(right - left + 1);
            int p1 = left, p2 = mid + 1;
            int p = 0;
            while (p1 <= mid || p2 <= right) {
                if (p1 > mid) {
                    sorted[p++] = sum[p2++];
                } else if (p2 > right) {
                    sorted[p++] = sum[p1++];
                } else {
                    if (sum[p1] < sum[p2]) {
                        sorted[p++] = sum[p1++];
                    } else {
                        sorted[p++] = sum[p2++];
                    }
                }
            }
            for (int i = 0; i < sorted.size(); i++) {
                sum[left + i] = sorted[i];
            }
            return ret;
        }
    }

    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int s = 0;
        vector<int> sum{0};
        for (auto &v: nums) {
            s += v;
            sum.push_back(s);
        }
        return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
    }
};

/**
 *  前缀和加归并排序
 *  先利用原数组算出前缀和（注意要包括没有值的前缀和即0），
 *  考虑下面这个情况
 *  两个升序排列数组n1，n2，找出所有下标对（i，j）满足 n2[j] - n1[i] 在upper与lower之间
 *  这就等价于求区间和在upper与lower之间，枚举方式为：
 *  初始情况 两个下标l，r指向n2开始处， i指向n1开始处
 *  顺序遍历l下标，直到n2[j] - n1[i] >= lower为止
 *  顺序遍历i下标，直到n2[r] - n1[i] > upper为止
 *  这样[l, r)区间包含的个数都满足lower与upper范围内
 *  这个时候++i，l，r却不需要重头开始遍历，因为有序，根据不等式从之前的位置继续遍历即可
 *
 *  利用这个特性，再辅助以归并排序过程的特性，可以直接解决
 * */


int main() {
    Solution solution;
    vector<int> res = {-2, 5, -1};
    cout << solution.countRangeSum(res, -2, 2);
}
