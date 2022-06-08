#include "iostream"
#include "algorithm"

using namespace std;
/**
 * 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
 * 路径和 是路径中各节点值的总和。
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 * 链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
 * */

/**
 * 本题可以利用动态规划的思想，路径的最大长度可以从从每个节点6个候选路径值中的最大值中取出最大值的最大值
 * 即，当前节点本身的值，左节点，右节点，当前节点+左子树（必须包含左节点）的最大路径长度，当前节点+右子树（必须包含右节点）的最大路径长度，当前节点+左子树（必须包含左节点）的最大路径长度+右子树（必须包含右节点）的最大路径长度
 * 同时，由于利用到动态规划，从树叶节点开始计算，每个节点都有为父节点提供候选项，但提供的候选项必须与父节点组成路径
 * 所以提供的的候选项为当前本身的值，当前节点+左子树（必须包含左节点）的最大路径长度，当前节点+右子树（必须包含右节点）的最大路径长度三个路径的最大值（还需根据左右子树是否存在，删减其中选项）
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int ans;
public:
    int maxPathSum(TreeNode *root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }


    int dfs(TreeNode *head) {
        if (head) {
            int leftVal = dfs(head->left);
            int rightVal = dfs(head->right);

            int allVal = leftVal + rightVal + head->val;
            int leftAllVal = head->val + leftVal;
            int rightAllVal = head->val + rightVal;

            int maxVal = max(allVal, max(leftAllVal, rightAllVal));
            maxVal = max(maxVal, head->val);

            if (head->left) maxVal = max(maxVal, leftVal);
            if (head->right) maxVal = max(maxVal, rightVal);

            ans = max(maxVal, ans);

            if (head->left && head->right) {
                return max(head->val, max(leftAllVal, rightAllVal));
            } else if (head->left) {
                return max(head->val, leftAllVal);
            } else if (head->right) {
                return max(head->val, rightAllVal);
            } else return head->val;


        } else return 0;
    }

    /**
     * 上面dfs方法逻辑的简单实现版本，只能说牛逼
     * */
    int dfs2(TreeNode *head) {
        if (head) {
            int leftVal = max(dfs(head->left), 0);
            int rightVal = max(dfs(head->right), 0);

            int maxVal = head->val + leftVal + rightVal;

            ans = max(ans, maxVal);

            return head->val + max(leftVal, rightVal);
        } else return 0;
    }
};