## 138. Copy List with Random Pointer
### sol
- Q: Copy the list to new list. And, in the node, there are two pointer including next and random.
- sol:
    - First, traverse the list and create the hash to map old node and new node.
    - Second, traverse the list again and use the hash to find new node and assign next and random.  
