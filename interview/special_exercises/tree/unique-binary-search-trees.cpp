#include "iostream"
#include "vector"


using namespace std;
/**
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 * 链接:https://leetcode.cn/problems/unique-binary-search-trees/
 * */

/**
 * 本题其实是个递归问题（转为动态规划，节省时间复杂度）
 * 一个搜索二叉树有多少种不同排法，其实就是确定好根节点，根节点两边节点的个数分别为n，m个
 * 则n个节点有多少种排法，m个节点有多少种排法（划分子问题），相乘辨识这个根节点的排法，遍历所有可能的
 * 根节点求和即可
 * */
class Solution {
public:
    int numTrees(int n) {
        int ans = 0;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            int tmp = 0;
            for (int j = 1; j <= i; ++j) {
                tmp += dp[j - 1] * dp[i - j];
            }

            dp[i] = tmp;
        }

        return dp[n];
    }
};

