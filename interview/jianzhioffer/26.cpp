#include "iostream"

using namespace std;

/**
 * 判断一棵树是否为另外一棵树的子树
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
private:
    bool isComplete;
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (A == NULL || B == NULL) return false;
        isComplete = false;
        search(A, B);
        return isComplete;
    }

    void search(TreeNode *a, TreeNode *bRoot) {
        if (a) {
            if (a->val == bRoot->val) {
                isComplete = isHave(a, bRoot);
            }

            if (!isComplete && a->left) search(a->left, bRoot);
            if (!isComplete && a->right) search(a->right, bRoot);
        }
    }

    bool isHave(TreeNode *a, TreeNode *b) {
        if (b == NULL) return true;
        if (a == NULL) return false;

        if (a->val != b->val) return false;

        return isHave(a->left, b->left) && isHave(a->right, b->right);
    }
};

