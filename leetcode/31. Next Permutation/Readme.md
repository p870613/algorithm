# Approach

1. find the break i index.
   How to find i index ? Find a element that is broken of increasing order from last element to first element.
   For example, {0, 3, 6, 4, 2} => the break i index is `index 1`
2. If the break point can't find, reverse the array.
3. Find a element that must be larger break point and be smallest in right-half break array.
4. swap 3.step element and break element and reverse array.

For example, 
{0, 3, 6, 4, 2} => 1. break point is index 1(3)
                => 2. the smallest element in right-half is 2, but it isn't larger than break point
                => 3. the second small element in right-half is 4, it is larger than break point.
                => 4. swap break point and element found in step 3, array is {0, 4, 6, 3, 2}
                => 5. reverse right half, array is {0, 4, 2, 3, 6} and it's answer. 
