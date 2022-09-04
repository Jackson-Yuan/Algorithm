#include "iostream"
#include "TreeNode.h"

using namespace std;
/**
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree
 * */

/**
 * 本题思路如下：
 * 设计一个带有返回值的递归函数，返回值表明最近的公共祖先节点，原因如下：
 * 若一个节点root，其p，q位于root的异处（左右两侧），则root即为p，q的公共祖先节点
 * 若分布在root的同一侧，则两侧的返回值必有一处为null，返回不是null的一侧即可
 * 若分布都不在root两侧，则直接返回null
 * 那么如何确保为最近呢？直接dfs深度到底，然后从底部回溯，回溯过程中，一旦确定好祖先节点，那么就是最近的，会一级级返回上来
 * 牛逼
 * */
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr && right == nullptr) return nullptr;
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }
};

