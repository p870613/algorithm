## 567. Permutation in String
### Sol
- Q: Give you two string, s and t. Find if s contain the a permutation of t.
- Sol:
    - Permutation is mean it have same len and same character in `t`. So, I use the map to record the characters in `t`.
    - `start` and `end` record the boundary of windows. 
    - If `end - start` is equal to `t.size()`, compare the map_s(start - end) and map_t. If they are same, return `true`. If not, move start and end to right.
    - If `end` is equal to `s.size()`, return `false` 
