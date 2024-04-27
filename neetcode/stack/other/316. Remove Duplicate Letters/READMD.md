### sol
- Q: Give a string, remove duplicate letter, and return the smallest in lexicographical order
- sol:
    - Traverse the string, and then track the last index per character in string.
    - Use stack to record the result and traverse the string and continue the character in stack
    - If current character is less than the stack.back element that isn't the last element , stack pop.
