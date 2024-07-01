/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool check(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL)
        return true;
    if (root == NULL || subRoot == NULL)
        return false;

    if (root->val != subRoot->val)
        return false;
    
    return check(root->right, subRoot->right) && check(root->left, subRoot->left);
}

bool traverse(struct TreeNode* root, struct TreeNode* subRoot) {
    if (check(root, subRoot)) {
        return true;
    }
    if (root != NULL)
        return traverse(root->right, subRoot) || traverse(root->left, subRoot);
    else
        return false;
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    return traverse(root, subRoot);
}
