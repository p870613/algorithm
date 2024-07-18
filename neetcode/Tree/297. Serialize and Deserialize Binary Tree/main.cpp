/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        seri(root);
        return seri_ret;    
    }
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    string seri_ret;
    void seri(TreeNode *root) {
        if (root != NULL) {
            seri_ret = seri_ret + to_string(root->val) + " ";
            seri(root->left);
            seri(root->right);
        } else {
            seri_ret = seri_ret + "# ";
        }
    }
    TreeNode* deserialize(istringstream& a) {
        string val;
        a >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(a);
        root->right = deserialize(a);
        return root;
    }

};
