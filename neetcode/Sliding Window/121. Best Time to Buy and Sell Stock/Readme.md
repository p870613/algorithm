## 121. Best Time to Buy and Sell Stock
### sol
- Q: give you array that present the price of stack. Find the maximun profit from transcation.
- sol:
    - Traverse the array and record the minimun price and maximun profit.
    - when travering, if meet the less price, replace that. And, use current price - minimux price = profit. Record the maximun profit.