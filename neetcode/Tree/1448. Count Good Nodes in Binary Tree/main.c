/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ret;
    void find_good_node(TreeNode* root, int n) {
        if (root == NULL)
            return;
        if (root->val >= n) {
            n = root->val;
            ret ++;
        }
        find_good_node(root->left, n);
        find_good_node(root->right, n);
    }
    int goodNodes(TreeNode* root) {
        ret = 0;
        find_good_node(root, root->val);
        return ret;      
    }
};
