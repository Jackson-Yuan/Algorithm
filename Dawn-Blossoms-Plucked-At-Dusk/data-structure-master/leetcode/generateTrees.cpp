/**
 *给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<TreeNode *> res;
public:
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }

    vector<TreeNode *> generate(int start, int end) {
        vector<TreeNode *> path;
        if (start > end) return path;

        for (int i = start; i <= end; i++) {
            vector<TreeNode *> left = generate(start, i - 1);
            vector<TreeNode *> right = generate(i + 1, end);

            if (left.size() > 0 && right.size() > 0) {
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        TreeNode *tmp = new TreeNode(i);
                        tmp->left = left[j];
                        tmp->right = right[k];
                        path.push_back(tmp);
                    }
                }
            } else if (left.size() == 0 && right.size() > 0) {
                for (int j = 0; j < right.size(); ++j) {
                    TreeNode *tmp = new TreeNode(i);
                    tmp->right = right[j];
                    path.push_back(tmp);
                }
            } else if (left.size() > 0 && right.size() == 0) {
                for (int j = 0; j < left.size(); ++j) {
                    TreeNode *tmp = new TreeNode(i);
                    tmp->left = left[j];
                    path.push_back(tmp);
                }
            } else {
                path.push_back(new TreeNode(i));
            }
        }


        return path;
    }
};
/**
 * 此题思路如下：
 * 1........n，应要列出所有二叉搜索树的组合，则不妨确定一个点i，根为i的的二叉搜索个数为左右子树个数相乘
 * 不妨设置一个递归函数，返回类型为start到end位置二叉搜索树的个数的数组，如上代码所述
 * */