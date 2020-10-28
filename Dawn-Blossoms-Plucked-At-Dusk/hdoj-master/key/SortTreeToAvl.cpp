/**
 * 将一颗二叉排序数，变成二叉平衡树
 * 思路：牛逼的思路先不谈，先介绍一个朴素的思路，将二叉排序树中序遍历，得一有序数组
 * 直接根据有序数组生成平衡二叉树
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> path;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

void insertFromBST(TreeNode *&root, int val) {
    if (root == nullptr) {
        root = new TreeNode;
        root->val = val;
        root->left = root->right = nullptr;
    } else if (root->val > val) {
        insertFromBST(root->left, val);
    } else {
        insertFromBST(root->right, val);
    }
}

void midOrder(TreeNode *root) {
    if (root) {
        midOrder(root->left);
        cout << root->val << " ";
        path.push_back(root->val);
        midOrder(root->right);
    }
}

/**根据有序数组生成平衡二叉树*/
TreeNode *sortTreeNodeAvl(int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode;
    root->val = path[mid];
    root->left = sortTreeNodeAvl(start, mid - 1);
    root->right = sortTreeNodeAvl(mid + 1, end);
    return root;
}

void preOrder(TreeNode *root) {
    if (root) {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    vector<int> array(7, -1);
    for (int i = 0; i < 7; ++i) {
        cin >> array[i];
    }

    TreeNode *root = nullptr;
    for (int j = 0; j < 7; ++j) {
        insertFromBST(root, array[j]);
    }

    midOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    cout << "------------------------" << endl;

    TreeNode *avlRoot = sortTreeNodeAvl(0, path.size() - 1);
    preOrder(avlRoot);
}