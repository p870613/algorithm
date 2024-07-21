## 199. Binary Tree Right Side View
- Q:imagine yourself standing on the right side of it
- A:
    - Using BFS
    - Using a queue, add node to the queue. 
    - `push_back` the first val to `return vector`.
    - `push_back` the right of current node and left of current node and `pop` the current node.
