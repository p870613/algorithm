### sol
- 題目: 
    - MinStack() initializes the stack object.
    - void push(int val) pushes the element val onto the stack.
    - void pop() removes the element on the top of the stack.
    - int top() gets the top element of the stack.
    - int getMin() retrieves the minimum element in the stack.
    - **Main point is getMin in stack, because you must find the minimin in stack using traverse.**, but time complexity must be O(1).  

- sol:
    - declare the new struct. In this struct, it store value and minimun in current stack.
    - when pushing node to stack, it check the the min of  last element in stack is less than cur value. If it is less than value, it will store min in new node. Otherwise, it must store value to min in new node.
