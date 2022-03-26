#include "iostream"
#include "algorithm"

using namespace std;
/**
 * ·�� ������Ϊһ������������ڵ�������ظ��ڵ�-�ӽڵ����ӣ��ﵽ����ڵ�����С�ͬһ���ڵ���һ��·�������� �������һ�� ����·�� ���ٰ���һ�� �ڵ㣬�Ҳ�һ���������ڵ㡣
 * ·���� ��·���и��ڵ�ֵ���ܺ͡�
 * ����һ���������ĸ��ڵ� root �������� ���·���� ��
 * ���ӣ�https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
 * */

/**
 * ����������ö�̬�滮��˼�룬·������󳤶ȿ��ԴӴ�ÿ���ڵ�6����ѡ·��ֵ�е����ֵ��ȡ�����ֵ�����ֵ
 * ������ǰ�ڵ㱾���ֵ����ڵ㣬�ҽڵ㣬��ǰ�ڵ�+�����������������ڵ㣩�����·�����ȣ���ǰ�ڵ�+����������������ҽڵ㣩�����·�����ȣ���ǰ�ڵ�+�����������������ڵ㣩�����·������+����������������ҽڵ㣩�����·������
 * ͬʱ���������õ���̬�滮������Ҷ�ڵ㿪ʼ���㣬ÿ���ڵ㶼��Ϊ���ڵ��ṩ��ѡ����ṩ�ĺ�ѡ������븸�ڵ����·��
 * �����ṩ�ĵĺ�ѡ��Ϊ��ǰ�����ֵ����ǰ�ڵ�+�����������������ڵ㣩�����·�����ȣ���ǰ�ڵ�+����������������ҽڵ㣩�����·����������·�������ֵ������������������Ƿ���ڣ�ɾ������ѡ�
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
     * ����dfs�����߼��ļ�ʵ�ְ汾��ֻ��˵ţ��
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