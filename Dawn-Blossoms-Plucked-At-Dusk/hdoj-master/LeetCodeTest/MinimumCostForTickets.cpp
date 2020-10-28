/**
 * 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。
 * 在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。
 * 火车票有三种不同的销售方式：
 * 一张为期一天的通行证售价为 costs[0] 美元；
 * 一张为期七天的通行证售价为 costs[1] 美元；
 * 一张为期三十天的通行证售价为 costs[2] 美元。
 * 通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张为期 7 天的通行证，
 * 那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。
 * 返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
private:
    bool m[367] = {false};
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        for (int i = 0; i < days.size(); ++i) {
            m[days[i]] = true;
        }

        vector<int> dp(367, INT_MAX);
        dp[366] = 0;
        for (int i = 365; i >= 1; --i) {
            if (m[i]) {
                if (i + 1 <= 366) dp[i] = min(dp[i], dp[i + 1] + costs[0]);
                if (i + 7 <= 366) dp[i] = min(dp[i], dp[i + 7] + costs[1]);
                if (i + 30 <= 366) dp[i] = min(dp[i], dp[i + 30] + costs[2]);
            } else {
                dp[i] = dp[i + 1];
            }
        }
        return dp[1];
    }
};
/**
 * 本题虽然隐约知道为动态规划，但很可惜，不太会动
 * 其实按照一年1~365天进行动态规划，dp[i]代表从第i天开始，到年末需要的最低票价价值
 * 若当前遍历的i不在days数组里，则dp值为i + 1 的值，因为此天不出行，越晚买越好
 * 若此天出行，则分别在i + 1，i + 3， i + 7 的dp值加上相应票价，选择最小值
 * 唯一注意的边界，要设第366天为0 这样便于递推的展开
 * */