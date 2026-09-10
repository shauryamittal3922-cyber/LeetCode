/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct res{
    int sum;
    int count;
};

struct res postOrder(struct TreeNode* root, int* ans){
    if(root == NULL) return (struct res){0, 0};

    struct res left = postOrder(root->left, ans);
    struct res right = postOrder(root->right, ans);

    int currSum = root->val + left.sum + right.sum;
    int currCount = 1 + left.count + right.count;

    if(currSum/currCount == root->val) (*ans)++;

    return (struct res){currSum, currCount};
}

int averageOfSubtree(struct TreeNode* root) {
    int match = 0;
    postOrder(root, &match);
    return match;
}