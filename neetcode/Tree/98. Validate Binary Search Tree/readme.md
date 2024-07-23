## 98. Validate Binary Search Tree
- Q: Given the root of binary tree, determine if it is a valid binary search tree
- A:
    - binary search tree => root->val > root->left->val, root->val > root->right->val 
    - Using recursive and bring the left and right to check if the binary search tree is valid or not.
