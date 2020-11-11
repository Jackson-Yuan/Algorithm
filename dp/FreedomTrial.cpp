/**
 * 电子游戏“辐射4”中，任务“通向自由”要求玩家到达名为“Freedom Trail Ring”的金属表盘，并使用表盘拼写特定关键词才能开门。
 * 给定一个字符串ring，表示刻在外环上的编码；给定另一个字符串key，表示需要拼写的关键词。您需要算出能够拼写关键词中所有字符的最少步数。
 * 最初，ring的第一个字符与12:00方向对齐。您需要顺时针或逆时针旋转 ring 以使key的一个字符在 12:00方向对齐，
 * 然后按下中心按钮，以此逐个拼写完key中的所有字符。
 * */
#include <algorithm>
#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<int> pos[26];
        for (int i = 0; i < ring.size(); i++) {
            pos[ring[i] - 'a'].push_back(i);
        }

        vector<vector<int>> dp(key.size(), vector<int>(ring.size(), INT_MAX));
        for (int i = 0; i < key.size(); i++) {
            for (auto j : pos[key[i] - 'a']) {
                if (i == 0) {
                    dp[i][j] = min(dp[i][j], 0 + clac(ring.size(), 0, j) + 1);
                    continue;
                }

                for (auto k : pos[key[i - 1] - 'a']) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + clac(ring.size(), k, j) + 1);
                }
            }
        }


        /**返回容器中的最小值*/
        return *min_element(dp.back().begin(), dp.back().end());
    }

    int clac(int len, int a, int b) {
        return min((len + a - b) % len, (len + b - a) % len);
    }
};
/**
 * 依然是操蛋的动态规划
 * dp数组的意义为长度为m的key(实际最大索引为m-1)，到索引为j的字符的最短距离(索引为j的字符，其实就是串key最后一个字符，只是这个字符可能在
 * ring中有多个位置，所以便利结束后，需要选出最小值)
 * 知道了意义，每次dp[i][j]的值都来自于dp[i-1][k]的最小值(k是串key当前字符前一个字符所处位置的索引，因为布置一个位置，所以必须
 * 全部便利取最小值)
 * */


