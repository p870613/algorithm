## Median of Two Sorted Arrays
### sol 
- Q: Find the median value in two array
- Sol: 
    - If total size of array is odd, find the total / 2. Otherwise, find the total/2 and total/2-1 and add them, divide 2. 
    - Implement a function that find the median value.
        - Find the middle of both arary. If the sum of middle is greater than target index, move one of array to left side. Compare the middle of both array. Move larger one to left side.
        - If the sum of middle is less than target index, move one of array to right side. Compare the middle of both array, move smaller one to right side.
        - The terminal condition is the left is greater than right in one of array. Return the other one, and index is target - left in other.
