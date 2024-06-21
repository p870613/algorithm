/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int ret = 0;
int depth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int l = depth(root->left);
    int r = depth(root->right);
    
    if (abs(l - r) > 1)
        ret = 1;
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root) {
    ret = 0;
    depth(root);
    
    if (ret)
        return false;
    return true;
}
