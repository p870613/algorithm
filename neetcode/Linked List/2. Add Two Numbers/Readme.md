## 2. Add Two Numbers
- Q: One list present a number. Add two list and return. For example, "2, 4, 3" and "5, 6, 4". The answer is "7, 0, 8" because 342 + 465 = 807.
- Sol:
    - Traverse the list and add two node value. If the value is greater than 10, the val in new node is new `value % 10` and store the `carry bit` that is `value / 10`.
