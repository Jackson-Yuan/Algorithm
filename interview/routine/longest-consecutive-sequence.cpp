#include "iostream"
#include "unordered_set"
#include "vector"

using namespace std;
/**
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 请你设计并实现时间复杂度为O(n) 的算法解决此问题。
 * 链接：https://leetcode.cn/problems/longest-consecutive-sequence
 * */

/**
 * 最直观的想法，排序之后判断但复杂度nlogn
 * 下面介绍o（n）的方法
 * 一个连续序列x, x+1, x+2，...., x+n
 * 若我们已知上面这个序列是最长序列，那么从x+1、x+2这些数为起点开始寻找是没有价值的
 * 所以需要跳过这些多余步骤，
 * 我们要枚举的数 x 一定是在数组中不存在前驱数 x-1x−1 的，不
 * 然按照上面的分析我们会从 x-1始尝试匹配，因此我们每次在哈希表中检查是否存在 x-1即能判断是否需要跳过了。
 *
 * 至于这么做复杂度为什么会是o（n）
 * 外层循环需要 O(n)的时间复杂度，只有当一个数是连续序列的第一个数的情况下才会进入内层循环，然后在内层循环中匹配连续序列中的数，
 * 因此数组中的每个数只会进入内层循环一次。根据上述分析可知，总时间复杂度为 O(n，符合题目要求。
 * */
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> num_set;
        for (const int &num: nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int &num: num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
