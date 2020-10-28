/**
 * 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums) {
        int all = 0;
        for (int i = 0; i < nums.size(); ++i) {
            all ^= nums[i];
        }
        int divide = 1;
        while ((divide & all) == 0) divide = divide << 1;
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (divide & nums[i]) {
                a ^= nums[i];
            } else b ^= nums[i];
        }

        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};
/**
 * 本题其实是位运算的一次综合运用
 * 如果数组里只有一个数为出现一次，其余均为一次，则遍历全员异或即可
 * 但此时有两个只出现一次，其余均出现两次的数组需要统计
 * 这时一个正常的想法是将这两个出现一次的数分到两个不同的组里，同时相同的数会被分到相同的组中
 * 想法归想法，实现起来还是费事的
 * 不妨设出现一次的两个数为a，b
 * 全员异或一次的值为a^b的值，记为all
 * 我们把all当成二进制看，二进制每一位要么0要么1
 * 为1代表a与b在此位置上的二进制不等
 * 为0代表a与b在此位置上的二进制相等
 * 找出这一位，就利用此位进行分组
 * 首先利用此为可以将a b区分，其次相同的数肯定能分到同一组
 * 完美符合条件
 * */