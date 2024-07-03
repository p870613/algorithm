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
    vector<vector<int>>ret;
    void f(struct TreeNode* root, int depth) {
        if (root == NULL)
           return;
           
        if (ret.size() < depth+1) {
            vector<int> *t = new vector<int>;
            ret.push_back(*t);
        }
            
        ret[depth].push_back(root->val);
        printf("%d %d\n", root->val, depth);
        f(root->left, depth+1);
        f(root->right, depth+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        f(root, 0);
        return ret;
    }
};
