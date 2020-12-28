/**
 * 给定一个整数数组prices ，它的第 i 个元素prices[i] 是一支给定的股票在第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        k = min(k, n / 2);
        vector<vector<int>> buy(n, vector<int>(k + 1));
        vector<vector<int>> sell(n, vector<int>(k + 1));

        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            buy[0][i] = sell[0][i] = INT_MIN / 2;
        }

        for (int i = 1; i < n; ++i) {
            /**每一轮的buy[i][0]单独都需要初始化，sell[i][0]则不需要，尤其状态转移所决定*/
            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
            }
        }

        return *max_element(sell[n - 1].begin(), sell[n - 1].end());
    }
};
/**
 * 首先明确一下概念，买进卖出算一笔交易
 * buy数组表示，第i天恰好进行j笔交易，且持有股票的最大利润
 * sell数组表示，第i天恰好进行j笔交易，且不持有股票的最大利润
 * 对于buy[i][j]，他有两种状态来源，若第i-1天不持有股票，则看sell[i-1][j]，因为要持有股票，还得减去prices[i]，即sell[i-1][j] - prices[i]
 * 或者第i-1天持有股票，则照抄buy[i-1][j]
 *
 * 同理对于sell[i][j]，若第i-1天不持有股票，则照抄sell[i-1][j]
 * 若第i-1天持有股票，则今天肯定要卖掉，为sell[i-1][j-1] + prices[i]
 *
 * 转移方差整完，就看边界了
 * 无论buy还是sell，i为0，j从1到k的值都是无意义的
 * 唯独i = 0 j = 0时，buy[i][j] = -prices[0]，理由是恰好进行了0笔交易，且你又持有股票，那么只有这个值符合要求
 * sell[i][j]也是一个道理
 * */