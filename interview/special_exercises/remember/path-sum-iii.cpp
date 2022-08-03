#include "iostream"
#include "unordered_map"
#include "../tree/TreeNode.h"

using namespace std;
/**
 * 给定一个二叉树的根节点 root，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

链接：https://leetcode.cn/problems/path-sum-iii
 * */

/**
 * 先说暴力解法，直接从树的每个节点开始一次dfs，查找是否能出现targetSum
 *
 *
 * 下面介绍一种o（n）的优化方法，题目要求求是否存在从父节点到子节点这条路径上的值是否为targetSum，在dfs遍历过程中
 * 我们可以保存一个父节点到叶子节点之间的这条路径上，父节点到每个子节点的值（前缀），每遍历到一个节点，利用父节点到这个节点的总和curr
 * 与targetSum作差得到diff，看在此之前的前缀中diff出现过没有，若有则代表，父节点到这个节点的路径，除去这个前缀所代表的路径（同样的父节点到这路径
 * 中间的某个节点），就是和为targetSum一条父节点至子节点的路径（这个地方父节点与前面的父节点不是同一个父节点）
 *
 * */

class Solution {
public:
    unordered_map<long long, int> prefix;

    int dfs(TreeNode *root, long long curr, int targetSum) {
        if (!root) {
            return 0;
        }

        int ret = 0;
        curr += root->val;
        if (prefix.count(curr - targetSum)) {
            ret = prefix[curr - targetSum];
        }

        prefix[curr]++;
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix[curr]--;

        return ret;
    }

    int pathSum(TreeNode *root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};

