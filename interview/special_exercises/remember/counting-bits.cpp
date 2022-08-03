#include "iostream"
#include "vector"

using namespace std;
/**
 * 给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。
 * 链接：https://leetcode-cn.com/problems/counting-bits/
 * */


/**
 * 统计一个数的二进制中1出现的次数
 *
 * 三种方法，第三种好说（但不适用于负数）
 * 第二种适用于正负数（需要规定好1的右移次数）
 * 第一钟适用于正负数，且块，核心思想在于x & （x - 1） 可使得x的最后一个1变为0
 * 
 * */
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for (int i = 0; i <= n; ++i) {
            ans.push_back(judge(i));
        }

        return ans;
    }


    int judge(int val) {
        int count = 0;
        while (val) {
            val = val & (val - 1);
            ++count;
        }

        return count;
    }

    int judge2(int val) {
        int count = 0;
        int i = 1;
        while (i != INT_MIN) {
            if (val & i) ++count;
            i = i << 1;
        }

        return count;
    }

    int judge3(int val) {
        int count = 0;
        while (val) {
            if ((val & 1) == 1) ++count;

            val >>= 1;
        }

        return count;
    }
};


