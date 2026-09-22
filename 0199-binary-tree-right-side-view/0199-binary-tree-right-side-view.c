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

void dfs(struct TreeNode* root, int depth, int* res, int* returnSize){
    if(root == NULL) return;

    if(depth == *returnSize){
        res[(*returnSize)++] = root->val;
    }

    dfs(root->right, depth+1, res, returnSize);
    dfs(root->left, depth+1, res, returnSize);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    * returnSize = 0;

    if(root == NULL) return NULL;

    int* result = malloc(100 * sizeof(int));
    dfs(root, 0, result, returnSize);

    return result;
}