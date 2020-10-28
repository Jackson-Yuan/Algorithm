/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int *createArray(int *target, int start, int end) {
    int *array = (int *) malloc(sizeof(int) * (end - start));
    int index = 0;
    for (int i = start; i < end; i++) {
        array[index] = target[i];
        index++;
    }

    return array;
}

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    if (preorder == 0 || inorder == 0) return 0;
    if (preorderSize == 0 || inorderSize == 0) return 0;
    if (preorderSize != inorderSize) return 0;
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode) * 1);
    root->val = preorder[0];
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == preorder[0]) {
            int *newPreOrder = createArray(preorder, 1, i + 1);
            int *newInOrder = createArray(inorder, 0, i);
            root->left = buildTree(newPreOrder, i, newInOrder, i);
            free(newPreOrder);
            free(newInOrder);
            newPreOrder = createArray(preorder, i + 1, preorderSize);
            newInOrder = createArray(inorder, i + 1, inorderSize);
            root->right = buildTree(newPreOrder, preorderSize - i - 1, newInOrder, inorderSize - i - 1);
            free(newPreOrder);
            free(newInOrder);
            break;
        }
    }

    return root;
}
/**
�������������������� ��ԭ��������
��ʵ�������õݹ� �𼶻�ԭ��С�Ķ�����
�������ǵݹ���õ�ʵ�� 
*/
