#include "iostream"
#include "vector"
#include "string"

using namespace std;

/**
 * 给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0开始的字符串s，它只包含字符'*' 和'|'，其中'*'表示一个 盘子，'|'表示一支蜡烛。
 * 同时给你一个下标从 0开始的二维整数数组queries，其中queries[i] = [lefti, righti]表示子字符串s[lefti...righti]
 * （包含左右端点的字符）。对于每个查询，你需要找到 子字符串中在 两支蜡烛之间的盘子的数目。
 * 如果一个盘子在 子字符串中左边和右边 都至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间。
 * 比方说，s = "||**||**|*"，查询[3, 8]，表示的是子字符串"*||**|"。子字符串中在两支蜡烛之间的盘子数目为2，
 * 子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
 * 请你返回一个整数数组answer，其中answer[i]是第i个查询的答案。
 * 链接：https://leetcode-cn.com/problems/plates-between-candles
 * */

/**
 * 这题乍一看 是寻找一个盘子左右最近的蜡烛位置，可以使用单调栈来解决
 * 随后只需判断给定范围内盘子是否存在蜡烛，但这样根据给定的数据规模直接超时
 *
 * 所以必须从给定范围，查找盘子个数这步操作入手优化时间复杂度。
 * 我们可以使用前缀和来优化，记录字符串每个位置的之前（包括本身）的盘子个数
 * 对于给定范围，我们寻找范围起点右边最近的蜡烛，范围终点左边最近的蜡烛
 * 然后利用这个两个蜡烛位置的前缀和直接相减得出结果
 *
 *
 * 但这边寻找范围起点右边最近的蜡烛，范围终点左边最近的蜡烛，单调栈模板
 * 可能不适用，因为单调栈以当前元素为基础寻找基于某个条件的第一个值，是不包括自身的
 * 如这个例子 **|**|***|，index=2的最右按照题目意思应该是其本身，但单调栈算出来是5（判断条件为：准备压入一个元素时，栈顶为‘*’就弹出至为非“*"。
 * 判断的时候，本身还不在栈中）.
 *
 * 当然我们也可以在进行最终前缀和运算的时候进行一次判断，若起点，终点的位置是”|“就无需利用由单调栈计算的位置数组，直接是其本身即可
 *
 * 本题采用双指针形式来完成此需求
 * */
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
        int n = s.length();
        vector<int> preSum(n);
        for (int i = 0, sum = 0; i < n; i++) {
            if (s[i] == '*') {
                sum++;
            }
            preSum[i] = sum;
        }
        vector<int> left(n);
        for (int i = 0, l = -1; i < n; i++) {
            if (s[i] == '|') {
                l = i;
            }
            left[i] = l;
        }
        vector<int> right(n);
        for (int i = n - 1, r = -1; i >= 0; i--) {
            if (s[i] == '|') {
                r = i;
            }
            right[i] = r;
        }
        vector<int> ans;
        for (auto &query : queries) {
            int x = right[query[0]], y = left[query[1]];
            ans.push_back(x == -1 || y == -1 || x >= y ? 0 : preSum[y] - preSum[x]);
        }
        return ans;
    }
};
