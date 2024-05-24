## 146. LRU Cache
### sol
- Q: Implement the LRU cache struct. It mean cache drop the lastest used node. In this question, it will `get` `put`.
- sol:
    - Use the double list linked. And, `head` is lastest used node and `tail` is least used node.
    - `get`: Get value from key and move this node to head.
    - `set`: Create new node if it doesn't exist. And move this node to head. If the number of node is greater than `capacity`, drop the tail node.
