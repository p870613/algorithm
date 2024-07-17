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
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        int right = max(dfs(root->right), 0);
        int left = max(dfs(root->left), 0);
        ret = max(ret, right + left + root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        ret = INT_MIN;
        dfs(root);
        return ret;
    }
};
