### sol
- 題目: 在一條路上有許多車, 不能超車且如果遇到一起的話，會用速度比較慢的車計算(塞車), 算有幾個車隊
- sol
    - 先用 position sort, 從後面開始算到達 target 的時間 (target-position)/speed
    - 如果position前面的時間比position後面的短，那就會 collosion，變成相同的車隊
    - 用 stack, 從後面開始放時間，如果後面的時間，小於等於stack.back()，就會撞在一起stack.pop；
    - return stack.size()
