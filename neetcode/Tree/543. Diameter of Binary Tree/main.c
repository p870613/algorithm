/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int ret;
int max (int a, int b) {
    if (a > b)
        return a;
    return b;
}
int cal_depth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int l = cal_depth(root->left);
    int r = cal_depth(root->right);
    int tmp = l + r;
    ret = max(tmp, ret);
    return 1 + max(l, r);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int left, right;
    struct TreeNode *l, *r;
    ret = 0;
    cal_depth(root);
    return ret;
}
