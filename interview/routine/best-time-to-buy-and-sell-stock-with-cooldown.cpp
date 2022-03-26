#include "iostream"
#include "vector"

using namespace std;

/**
 * 给定一个整数数组prices，其中第prices[i]表示第i天的股票价格。
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
 * */

/**
 * 最佳解法，动态规划，只是状态的定义需要点水平才能定义出来
 * 定义出来后，转移方程很好写
 * */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        // f[i][0]: 手上持有股票的最大收益
        // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[n - 1][1], f[n - 1][2]);
    }
};

/**
 * 这是深搜版记忆化递归写法
 * 怎么说呢，ps数组存储以start位置开始买入股票之后的最大收益（可能买多次）
 * 循环结束后，与邻近位置再做一次比较（相当于比较不同递归开始的起点值，为啥只比较下一个，因为下一个的递归里会比较下下一个，等价于枚举了所有递归起点的最大值）
 * 牛逼
 * */
class Solution2 {
private:
    vector<int> ps;
public:
    int maxProfit(vector<int> &prices) {
        ps = vector<int>(prices.size(), INT_MAX);
        return deal(0, prices);
    }

    int deal(int start, vector<int> &prices) {
        if (start >= prices.size()) {
            return 0;
        }

        int max_profit = 0;

        if (ps[start] != INT_MAX) {
            return ps[start];
        }

        for (int i = start + 1; i < prices.size(); i++) {
            int profit_now = prices[i] - prices[start];
            int profit_after = deal(i + 2, prices);
            int profit_total = profit_now + profit_after;

            max_profit = max(max_profit, profit_total);
        }

        max_profit = max(max_profit, deal(start + 1, prices));
        ps[start] = max_profit;
        return max_profit;
    }
};