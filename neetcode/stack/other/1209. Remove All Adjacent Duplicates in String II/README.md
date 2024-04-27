## 1209. Remove All Adjacent Duplicates in String II
- Q: Give s string and integer k, k is duplicate removal consists choosing k. Remove then from s and return result.
- sol:
    - Use stack to trace the character and frquency.
    - If frequnecy is equal the k, and then pop from stack. Otherwise, frequency increment 1.
    - Finally, consist of the string using the character and frequency
