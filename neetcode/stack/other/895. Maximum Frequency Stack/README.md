## 895. Maximum Frequency Stack
### sol
- Q: stack-like data struct to push element and pop the most frequent element from stack

- sol: 
    - Use map to track the frequency and use map to map the frequency and stack and track the maxfrequency
    - push: find the frequency of value, and increment by 1, finally push the frequency's stack
    - pop: Use maxfrequency to pop
