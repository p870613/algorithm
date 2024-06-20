/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max_depth = 0;
void cal_depth(struct TreeNode *root, int depth) {
    if (root == NULL)
        return;

    if (depth > max_depth)
        max_depth = depth;

    
    if (root->left)
        cal_depth(root->left, depth + 1);
    if (root->right)
        cal_depth(root->right, depth + 1);
       
}
int maxDepth(struct TreeNode* root) {
    max_depth = 0;
    cal_depth(root, 1);
    return max_depth;
}
