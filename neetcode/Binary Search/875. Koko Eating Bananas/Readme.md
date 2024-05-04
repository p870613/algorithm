## Koko Eating Bananas
- Q： koko love to eat banana. It eat the k banana in 1 hour. But, there are several pile of banana. Koko doesn't eat the different pile of banana in an hour. The question give you the number of each banana and hour. please find the min k and make koko eat the banana in each hour.
- Sol:
    - Koko want to eat the banana in each hour, so we must find the k's range. The range in range is 1 to max number of the pile banana.
    - As the range is known, we can use loop to traverse every possiblity. But, it's not efficient.
    - We can use the binary search to find min k. First, implement a function that caluate the hour. If the hour is greater than target hour, it mean the k is too small. So, move the left to middle + 1. Otherwise, move the right to middle - 1.
