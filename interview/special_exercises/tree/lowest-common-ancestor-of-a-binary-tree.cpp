#include "iostream"
#include "TreeNode.h"

using namespace std;
/**
 * ����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
 * �ٶȰٿ�������������ȵĶ���Ϊ���������и��� T �������ڵ� p��q������������ȱ�ʾΪһ���ڵ� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����
 * ���ӣ�https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree
 * */

/**
 * ����˼·���£�
 * ���һ�����з���ֵ�ĵݹ麯��������ֵ��������Ĺ������Ƚڵ㣬ԭ�����£�
 * ��һ���ڵ�root����p��qλ��root���촦���������ࣩ����root��Ϊp��q�Ĺ������Ƚڵ�
 * ���ֲ���root��ͬһ�࣬������ķ���ֵ����һ��Ϊnull�����ز���null��һ�༴��
 * ���ֲ�������root���࣬��ֱ�ӷ���null
 * ��ô���ȷ��Ϊ����أ�ֱ��dfs��ȵ��ף�Ȼ��ӵײ����ݣ����ݹ����У�һ��ȷ�������Ƚڵ㣬��ô��������ģ���һ������������
 * ţ��
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

