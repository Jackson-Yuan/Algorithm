/**
 * 硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <String.h>

using namespace std;

class Solution {
private:
    int dp[10000001];
public:
    int waysToChange(int n) {
        int coins[4] = {1, 5, 10, 25};
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < 4; ++i) {
            for (int j = coins[i]; j <= n; ++j) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;
            }
        }

        return dp[n];
    }
};

int main() {
    Solution solution;
    cout << solution.waysToChange(6);
}
/**
 * 是个完全背包问题，佛了 咋不上天的
 * 开始的时候虽然知道是dp 但以为递推式是
 * dp[n] = dp[n-5] + dp[n - 1] + dp[n - 15] + dp[n - 25[
 * 但这种递推式是错误的,因为 会出现重复的组合.
 * 真正的思路是完全背包解法
 * dp[i][j] 代表前i个硬币面值为j有多少个组合
 * 因为是完全背包 dp[i][j] = dp[i - 1][j] 或 dp[i][j - coins[i]](完全背包嘛,就不需要i-1了) + dp[i - 1][j]
 * 然后可以利用空间优化直接一波带走
 * */