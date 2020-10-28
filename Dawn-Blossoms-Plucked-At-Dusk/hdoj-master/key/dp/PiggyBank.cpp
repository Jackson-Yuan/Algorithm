/**
 * hdoj-1114 完全背包
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct coin {
    int weight;
    int cost;
};

int main() {
    int count;
    cin >> count;
    while (count--) {
        int base, sum;
        cin >> base >> sum;
        sum -= base;
        int n;
        cin >> n;
        vector<coin> coins;
        for (int i = 0; i < n; ++i) {
            coin current;
            cin >> current.cost >> current.weight;
            coins.push_back(current);
        }

        /* vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX));
         dp[0][0] = 0;*//**此题要求精确装满，所以要这样设边界，dp的状态意义是前i个硬币，重量恰好为j的最小价值*//*
        for (int i = 1; i <= n ; ++i) {
            for (int j = 0; j <= sum ; ++j) {
                coin current = coins[i - 1];
                int val = sum / current.weight;
                for (int k = 0; k <= val ; ++k) {
                    if (k * current.weight <= j && dp[i - 1][j - k *current.weight] != INT_MAX){
                        int compare = min(dp[i - 1][j], dp[i - 1][j -  k *current.weight] + k * current.cost);
                        dp[i][j] = min(compare, dp[i][j]);
                    } else dp[i][j] = min(dp[i - 1][j], dp[i][j]);
                }
            }
        }


        if (dp[n][sum] != INT_MAX){
            cout << "The minimum amount of money in the piggy-bank is " << dp[n][sum] << endl;
        }else   cout << "This is impossible." << endl;*/

        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            coin current = coins[i - 1];
            for (int j = current.weight; j <= sum; ++j) {
                if (dp[j - current.weight] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - current.weight] + current.cost);
                }
            }
        }

        if (dp[sum] != INT_MAX) {
            cout << "The minimum amount of money in the piggy-bank is " << dp[sum] << "." << endl;
        } else cout << "This is impossible." << endl;
    }

    return 0;
}
/**
 * 此题就是完全背包，且加了了条件，要求重量恰好为j而不是以往的不超过j，这时需要在初始化上下波功夫
 * 同时完全背包尽量使用空间优化的方法，注释部分是不采用空间优化，不仅费空间，还费时
 * */