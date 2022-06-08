#include "iostream"
#include "vector"

using namespace std;

/**
 * 双指针的应用，初始一个指着头，一个指着尾
 * 头尾分别寻找到第一个非奇数，非偶数，调换即可
 * */
class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            if (nums[begin] & 1) ++begin;
            else {
                if (nums[end] & 1) {
                    int tmp = nums[end];
                    nums[end] = nums[begin];
                    nums[begin] = tmp;
                    ++begin;
                    --end;
                } else {
                    --end;
                }
            }
        }

        return nums;
    }
};
