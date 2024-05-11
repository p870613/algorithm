## 239. Sliding Window Maximum
### Sol
- Q: Give you array and value `k`. Return a array that contain the maximun of every window in `k`.
- Sol:
    - Use the dequeu to record the maximax of window. The deque is `monotonically decreasing array`. 
    - Use the `start` and `end` to record the boundary of windows.
    - Traverse the array. Push the `end` to deque. if there are element that is less `nums[end]`, remove it from deque. it can check it from back because deque is `decreasing order`.
    - If `end - start` is equal to `k`, move the `deque.front()` to `return array`. And, move the `start` and `end` to right. If `deque,front() >= start`, remove it from deque.
    - Finally, return the array.
