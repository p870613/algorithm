## 105. Construct Binary Tree from Preorder and Inorder Traversal
- Q: Given two interger arrays preorder and inorder. And return the binary tree.
- A:
    -  preorder => the root node is first element, {root, left, right}
    -  inorder => the root node is in middle, {left, root, right}
    -  Using the preorder to know the value of root.
    -  Using the inorder to divide left subtree and right subtree
    - Using recursive to assign the `root->left` and `root->right`
