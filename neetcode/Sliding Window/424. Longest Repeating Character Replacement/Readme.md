## 424. Longest Repeating Character Replacement
### sol
- Q: Give you string and value k. Find the longest repeating character with k replacement. For example: string is `aaaabab` and k is 2. you can replace `b` with `a` twice. Return the maximun len of repeating character.
- Sol:
    - Use `max_freq` to record the counter of maximun freqency character.
    - Use map to record the counter of character.
    - `start` and `end` record the boundary of index with longest repeating with `k` replacement.
    - Traverse the string and record the `max_freq`. `max_freq < map[current] ? map[current] : max_freq`
    - If `end - start - max_freq` is less than k, it mean the time of replacement is less `k` times. So, move `end` to right and map\[`end`\] ++
    - If `end - start - max_freq` is greater than k, it mean the time of replacement is greater than `k` times, move `start` to right and map\[`start`\] -- 
