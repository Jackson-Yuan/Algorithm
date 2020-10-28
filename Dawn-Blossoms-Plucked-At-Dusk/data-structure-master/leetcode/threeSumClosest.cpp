/**
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
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
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());

        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); ++i) {
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int value = nums[i] + nums[start] + nums[end];
                if (check(value, target) < check(res, target)) {
                    res = value;
                } else if (value > target) --end;
                else if (value < target) ++start;
                else return value;
            }
        }


        return res;

    }

    int check(int a, int b) {
        if (a - b < 0) return b - a;
        else return a - b;
    }
};
/**
 * 此题就是强调一下线性表中双指针这个关键操作
 * 此题，可以无脑暴力所有组合，进行比较，但复杂度较高为n^3
 * 但若利用双指针，会降成n^2
 * 但运用双指针也无脑暴力了所有情况（再排序的情况下）
 * 所以排序加双指针不仅可以暴力还可降低复杂度
 * */