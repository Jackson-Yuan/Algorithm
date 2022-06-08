#include "iostream"
#include "vector"

using namespace std;

/**
 * 本题暴力方法不多bb
 * 介绍一下二分，二分的利用时机基本是排序的一维数组
 * 这道题目里面有两个排序的非递减小数组，尝试利用二分来解决
 * 我们可以得到前面排序数组的所有元素都恒大于后面排序数组的元素
 * 这为二分创造了条件，我们固定【start，end】区间，取中间的元素
 * 当中间元素大于start位置元素，表明在前面的排序数组里，我们将start变为mid（而非mid+1）
 * 同理若小于则表明在后面排序数组，end变为mid（而非mid+1），不令他为mid+1是为了保证
 * start最后可以指向前面排序数组的最后一个，end可以指向后面排序数组的第一个
 * 这也是我们寻找到目标的条件。基于此想法，循环的条件也呼之欲出，即start位置的元素要恒大于等于end位置的元素
 * （若不满足这个条件，代表就是个顺序数组，旋转了0个）
 *
 * 但也有这么一种情况如【1，0，1，1，1】，【1，1，1，0，1】这种也符合题目条件，但如果仅按照这个想法无法判断它归属于
 * 前面还是后面，只能依靠顺序查找
 *
 *
 * 此题特判条件多，一次作对约等于不可能
 * */
class Solution {
public:
    int minArray(vector<int> &numbers) {
        if (numbers.empty()) return 0;

        int start = 0, end = numbers.size() - 1;

        while (numbers[start] >= numbers[end]) {
            int mid = (end - start) / 2 + start;

            if (end - start == 1) {
                return numbers[end];
            }

            if (numbers[start] == numbers[mid] && numbers[mid] == numbers[end]) {
                int ans = INT_MAX;
                for (int i = start; i <= end; ++i) {
                    if (numbers[i] < ans) ans = numbers[i];
                }

                return ans;
            }

            if (numbers[mid] >= numbers[start]) {
                start = mid;
            } else {
                end = mid;
            }

        }

        return numbers[start];
    }
};
