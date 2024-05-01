### sol
- 先 traverse element, 並使用 map 去紀錄次數
    - example: [1, 1, 1, 2, 2, 3] => {1:3, 2:2, 3:1}
- 之後用 frequency 去存
    - `vector<unordered_set<int>> freq;`
    - 用次數當成是 freq 的 index
        - example: [1, 1, 1, 2, 2, 3] => {1:3, 2:2, 3:1}
        - freq => [3, 2, 1]
