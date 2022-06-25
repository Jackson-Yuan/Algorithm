//
// Created by admin on 2022/6/13.
//

#ifndef ALGORITHM_TREENODE_H
#define ALGORITHM_TREENODE_H


struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    };
};


#endif //ALGORITHM_TREENODE_H
