### sol
- Q: Give an array hights, represent the histogram's bar height. Finallym **return the largest rectangle** in the histogram.

- sol: 
    - Use stack to track the height and starting index.
    - If the current value is greater than `stack.back()` height, push_back(start index, current height)
    - If the current value is less than `stack.back()` height, stack pop and record the start index.
    - Last, traverse the stack, use last index - start index storing in stack * height.
