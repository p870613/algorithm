class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[10001] = {100};

        fill_n(dp, 10001, INT_MAX-1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                }
                    
            }
        };
        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
    }
};
