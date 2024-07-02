/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL)
        return NULL;
    if (root->val == p->val || root->val == q->val)
        return root;

    struct TreeNode *t1 = NULL, *t2 = NULL;
    if ((root->val > p->val) || (root->val > q->val))
        t1 = lowestCommonAncestor(root->left, p, q);
    if ((root->val < p->val) || (root->val < q->val))
        t2 = lowestCommonAncestor(root->right, p, q);
    
    if (t1 != NULL && t2 != NULL)
        return root;
    if (t1 != NULL || t2 != NULL)
        return t1!=NULL ? t1 : t2;
    return root; 
}
