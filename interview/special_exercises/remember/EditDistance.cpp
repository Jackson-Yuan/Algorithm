/**
 * 给你两个单词word1 和word2，请你计算出将word1转换成word2 所使用的最少操作数。
 * 你可以对一个单词进行如下三种操作：
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 * 连接：https://leetcode.cn/problems/edit-distance/
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        for (int i = 1; i <= word1.length(); ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= word2.length(); ++i) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= word1.length(); ++i) {
            for (int j = 1; j <= word2.length(); ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }

        return dp[word1.length()][word2.length()];
    }
};
/**
 * 动态规划思想
 * dp[i][j]代表word1前i个字符转为word2前j个字符所需的最小步数
 * 先设置边界:
 * dp[i][0] = i代表了前i个转为0个需要几步，显而易见，得删除i次
 * dp[0][i] = i 同理
 * 递推式:
 * 若当前i,j指向的字符相等，那么dp[i][j] = dp[i - 1][j - 1]
 * 若不等，dp[i - 1][j]表示删除操作 dp[i][j - 1]表示插入操作 dp[i - 1][j - 1]表示替换操作 有点吊哦
 * 取这三者最小加1即为dp[i][j]最小值
 * */