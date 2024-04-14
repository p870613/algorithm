### sol
- 找水的總合
- 基本上就是用 min(maxl, maxr), 然後減裡面的面積
- 可以用 array 先存 maxr maxl 之後用 min(maxr, maxl) - h[i]
- example
    

| hight | 0 | 1 | 0 | 2 | 1 | 0 | 1 | 3 | 2 | 1 | 2 | 1 |
| ----- | - | - | - | - | - | - | - | - | - | - | - | - |
| maxl  | 0 | 0 | 1 | 1 | 2 | 2 | 2 | 2 | 3 | 3 | 3 | 3 |
| maxr  | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 2 | 2 | 2 | 1 | 0 |
| reselt| 0 | 0 | 1 | 0 | 1 | 2 | 1 | 0 | 0 | 1 | 0 | 0 |
min(maxl, maxr) - height

=> 1 + 1 + 2 + 1 + 1 = 6

- 優化
    - 用左右夾擊的方式 去找 maxr, maxl
    - maxl, maxr 誰小 移動誰
    - 一樣使用 min(maxl, maxr) - height 
