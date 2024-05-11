## 3. Longest Substring Without Repeating Characters
### sol
- Q: Give you string. Find the longest the substring with duplicate.
- Sol:
    - Traverse the string and use the `start` and `end` to record the index of substring without duplicate
    - Use the map to record current character (string\[start\] - string\[end\]).
    - If current character is not duplicate with map, `end` is increased by 1 and add current character to map. After that, record the maximun string.
    - If current character is duplicate with map, remove string\[`start`\] from map and `start` is increased by 1.
