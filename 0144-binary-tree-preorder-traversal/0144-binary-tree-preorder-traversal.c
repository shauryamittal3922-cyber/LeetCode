/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void traverse(struct TreeNode* root, int* res, int* returnSize){
    if(root == NULL) return;

    res[(*returnSize)++] = root->val;
    traverse(root->left, res, returnSize);
    traverse(root->right, res, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(100 * sizeof(int));
    * returnSize = 0;

    traverse(root, result, returnSize);

    return result;
}