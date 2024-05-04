## Time Based Key-Value Store
### sol
- Q: Give 'set' and 'get'. 'set'  have the 'timeout', 'key'm 'value'. 'get' have the 'key' and 'time' and then find the current timeout or previous timeout.
- sol:
    - Use the `unodered_map` the stored the key and vector that store `value` and `timeout`
    - Set use map to find corresponding value and push back
    - get use binary search to find timeout. If target is less than value in middle, move to left side. Otherwise, store the middle to tmp and move to right side.
