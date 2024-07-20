## 543. Diameter of Binary Tree
- Q: Return the longest path between any two node
- sol:
    - Using DFS (recursive)
    - Calulate the the longest path of left side and right side
    - if the left + right is greater than max, store,
    - So, the recursive function only return the max longest in right side or left side and store the max diameter.
