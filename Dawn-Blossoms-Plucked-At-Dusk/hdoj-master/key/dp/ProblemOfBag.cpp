/**
 * 经典0-1背包问题
 * n个物品(体积，重量)，放入体积为allVolume的背包中，如何放使重量最大
 * */
/**
 * hdoj 2191 多重背包
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct good {
    int cost;
    int weight;
    int number;
};

int main() {
    int n;
    cin >> n;
    while (n--) {
        int allCost, sum;
        cin >> allCost >> sum;
        vector<good> goods;
        for (int i = 0; i < sum; ++i) {
            good current;
            cin >> current.cost >> current.weight >> current.number;
            goods.push_back(current);
        }

        vector<vector<int>> dp(sum + 1, vector<int>(allCost + 1, 0));
        for (int i = 1; i <= sum; ++i) {
            good current = goods[i - 1];
            for (int j = 0; j <= allCost; ++j) {
                for (int k = 0; k <= current.number; ++k) {
                    if (j >= k * current.cost) {
                        /**0-1背包时，这个地方不需跟dp[i][j]本身比较*/
                        /**但完全背包，多重背包时，需要将其转化为0-1背包，但dp[i][j]会遭到多次修改，所以需要跟其自身比较*/
                        int compare = max(dp[i - 1][j], dp[i - 1][j - k * current.cost] + k * current.weight);
                        dp[i][j] = max(dp[i][j], compare);
                    } else dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
            }
        }

        cout << dp[sum][allCost] << endl;
    }

    return 0;
}
/**
 * 其余如完全背包与多重背包都是0-1背包变化而来
 * 因为0-1背包默认每个物品只能放一次
 * 完全，多重都是对放入物品数量在次数上有了更宽泛的要求可以放入多个)(如上图所示的关于k变量的循环)
 * */