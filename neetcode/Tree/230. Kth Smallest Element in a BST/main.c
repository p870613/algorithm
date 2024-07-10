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
    void find_k(TreeNode* root, int& k) {
        if (root == NULL)
            return;
        
        find_k(root->left, k);
        k --;
        if (k == 0) {
            ret = root->val;
            return;
        }
        find_k(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        ret = 0;
        // count = 0;
        find_k(root, k);
        return ret;    
    }
};
