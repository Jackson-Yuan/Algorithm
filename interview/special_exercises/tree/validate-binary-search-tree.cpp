#include "iostream"
#include "TreeNode.h"

using namespace std;
/**
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 * 有效 二叉搜索树定义如下：
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 链接：https://leetcode.cn/problems/validate-binary-search-tree
 * */

/**
 * 这道题目一个最简单的方法，直接中序遍历塞进一个数组
 * 看数组是否递增
 * 但在卷王遍地的今天，这样会被认为空间复杂度高
 *
 * 下面介绍直接在递归过程中直接进行判断的方法
 * 主要是需要设置一个lower和upper来限制判断当前节点的取值范围以此进行判断（很巧妙）
 *
 * 底下还有个错误版本，错误之处在于，它只是单纯地在考虑一个节点是否大于其左节点，小于其右节点，而非
 * 大于其左子树，小于其右子树
 * 如这个例子：
 * 5
 * 4,6
 * null.null.3.7
 * */
class Solution {
public:
    bool helper(TreeNode *root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode *root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBSTWithWrong(TreeNode *root) {
        if (root) {
            bool left = isValidBST(root->left);
            bool right = isValidBST(root->right);
            if (left && right) {
                if (root->left != nullptr && !(root->val > root->left->val)) left = false;
                if (root->right != nullptr && !(root->val < root->right->val)) right = false;
                return left && right;
            } else return false;
        } else return true;
    }
};