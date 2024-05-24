## 141. Linked List Cycle
- Q: Find the list if the cycle list is or not.
- Sol: 
    - Use `slow` and `fast` to traverse the list.
    - `slow` move one node once and `fast` move two node once.
    - if `slow` meet `fast`, it mean the list is cycle list. Otherwise, `fast` is meet NULL, it mean the list is not cycle list.
