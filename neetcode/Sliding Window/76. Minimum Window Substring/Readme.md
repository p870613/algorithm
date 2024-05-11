## 76. Minimum Window Substring
### Sol
- Q: Give you two string `s` and `t`. Find the minimun of substring in s that every character in t.
- Sol
    - Use map to record the every character in `t`.
    - Use the `start` and `end` to record the boundary of window.
    - Use `start_index` and `len` to locate the minimun substring in s
    - Use `score_s` and `score_t` to record if the frequency of character is greater than the number of frequency in t or not.
    - Travese the string, if meet the character not in t, continue it.
    - if `score_s` is less than `score_t`, `end` is increasing by 1 and add character to `map_s`. check if `map_s[s[end]]` is greater or equal to `map_t[s[end]]`. If yes, `score_s ++`.
    - If `score_s` is equal to `score_t`, check if `end - start` is less than `len`. If yes,  record the `start_index` and `len`.
    - Finally, return substring of`start_index` with `len` in s.
