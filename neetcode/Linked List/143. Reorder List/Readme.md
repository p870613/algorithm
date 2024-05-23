## 143. Reorder List
### sol
- Q: Reorder the List `L0 → L1 → … → Ln - 1 → Ln` to `L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …`
- sol: 
    - It can divide list to two list, one is `L1 -> Ln/2` and other one is `Ln/2 -> Ln`. And, reverse the later list. Lastly, merge two list.
    - Use the `slow` and `fast` to find the middle of list
        - `slow`: Move one node once
        - `fast`: Move two node once
