## 25. Reverse Nodes in k-Group
- Q: Give you a list and the value `k`. Reverse the list in every `k` node. If the number of node is not a multiple of k then left-out nodes, in the end, should remain as it is. For example, `[1, 2, 3, 4, 5]` => `[2, 1, 4, 3, 5]` 
- sol: 
    - Traverse the list and count the node
    - If count is equal to k, store this node as `reverse head`.
        - First, store the current next node and remove the current next node.
        - Reverse the `reverse head` and add the node to return list
        - Move the next node to current node
