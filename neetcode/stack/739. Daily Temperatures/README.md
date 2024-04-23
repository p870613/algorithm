### sol
- 題目: 給你一個 array 裡面是溫度 看幾天之後溫度是上升的 
- sol:
    - 可以用 stack 的方式檢查
    - 把溫度的 index 放進 stack, traverse array，如果現在的溫度大於stack 裡面的值, 就可以用 stack.back() - cur index，值到stack 裡面沒有值為止
