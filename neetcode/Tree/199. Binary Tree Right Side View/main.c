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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int>ret;
        if (root == NULL)
            return ret;
        q.push(root);

        while (!q.empty()) {
            ret.push_back(q.front()->val);
            int s = q.size();

            for(int i = 0; i < s; i++) {
                if (q.front()->right != NULL) {
                    q.push(q.front()->right);
                }       
                if (q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                q.pop();        
            }
        }
        return ret;
         
    }
};
