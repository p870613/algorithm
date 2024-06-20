/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;
    
    struct TreeNode *tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    if (root->left)
        invertTree(root->left);
    if (root->right)
        invertTree(root->right);
    return root;   
}
