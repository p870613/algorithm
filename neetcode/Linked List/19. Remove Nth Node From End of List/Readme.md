## 19. Remove Nth Node From End of List
### sol
- Q: Remove the nth node from end of list. for example, "1 2 3 4 5" remove 2 from end of list. The answer is "1 2 3 5"
- sol
    - if list len is m, remove the n node from end. It mean remove the `m-n` from start of list.
    - Record the `dummy` to move the node to n node. And then, use `del_node` to move the mode to `m-n` node.
    - The `del_node` can locate using `dummy` node. In this moment, `dummy` is located at the n. As moving the `dummy`, moving the `del_node` until `dummy` is end of list.
    - Finally, the `del_node` locate at `m-n` and remove it from list. 
