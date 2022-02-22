#include "iostream"
#include "vector"

using namespace std;


/**
 * 本题一般方法都是直接双重for循环暴力枚举
 * 我们不妨这样想，股票最大利润即最大卖出价格减去最小买入价格 且对应时间也必须符合逻辑
 * 遍历数组，我们可以将当前遍历的元素视为我要卖出的价格，前面维护一个之前的最小买入价
 * 这样遍历完，最大价格也出来了
 * */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        if (prices.size() < 2) return ans;
        int minIn = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - minIn > ans) ans = prices[i] - minIn;

            if (prices[i] < minIn) minIn = prices[i];
        }

        return ans;
    }
};