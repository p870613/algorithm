## 21. Merge Two Sorted Lists
### sol
- Q: Merge two sorted list to a sorted list
- Sol:
    - traverse two list
        - use `cur1` and `cur2` to track node
        - use `ret` as return node
    - Decide the `ret` next node
        - if `cur1->val > cur2->val`,  `ret->next = cur2`
        - else `ret->next->cur1` 
    - End of loop, `cur1` or `cur2` isn't end of list. So insert the portion of remaining list to `ret`
