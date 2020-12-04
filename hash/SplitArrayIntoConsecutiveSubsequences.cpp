/**
 * 给你一个按升序排序的整数数组 num（可能包含重复数字），
 * 请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。
 * 如果可以完成上述分割，则返回 true ；否则，返回 false 。
 * */
#include "iostream"
#include "map"
#include "vector"

using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &nums) {
        map<int, int> count;
        map<int, int> end;
        for (int i = 0; i < nums.size(); ++i) {
            ++count[nums[i]];
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (count[nums[i]]) {
                int pre = end[nums[i] - 1];
                if (pre > 0) {
                    --count[nums[i]];
                    --end[nums[i] - 1];
                    ++end[nums[i]];
                } else {
                    int val1 = count[nums[i] + 1];
                    int val2 = count[nums[i] + 2];
                    if (val1 > 0 && val2 > 0) {
                        --count[nums[i]];
                        --count[nums[i] + 1];
                        --count[nums[i] + 2];
                        ++end[nums[i] + 2];
                    } else return false;
                }
            }
        }

        return true;
    }
};
/**
 * 此题还有个限制条件没说，即升序的数组相邻两项差值小于等于1
 * 贪心玩法，核心思路就是尽可能延长每个子序列
 * 为此建立两个map，一个map统计数字的个数，一个map统计以次数结尾子序列的个数
 * 先遍历一波，统计每个数的出现个数
 * 第二次遍历时，每选取一个数，先看其前面一个数是否有以它结尾的子序列，有的话加入，并更改相应数值
 * 否则，查看后两个数的个数是否都大于0，若不是则直接返回false
 * */