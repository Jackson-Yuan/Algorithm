/**
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
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
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};
/**
 * 此题核心思想:
 * 设g（n）为1到n搜索二叉树的个数
 * f（i，n）为1到n中以i为根的搜索二叉树的个数
 * 显然g（n） = ∑f（i，n）
 * 而f（i，n）又为何物？
 * 距离：1234567
 * 设3为根，则f（3，n）为【1,2】与【4,5，6,7】二叉搜索树个数的乘积
 * 又因个数与其内容无关系所以【1,2】看成g（2），【4，5,6,7】看成g（4）
 * 即f（i，n） = g（i-1）*g（n-i）
 * */