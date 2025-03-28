class Solution {
public:
    int sum(vector<int>& nums) {
        int s = 0;

        for (int i = 0; i < nums.size(); i++)
            s = nums[i] + s;
        return s;
    }
    
    bool canPartition(vector<int>& nums) {
        int s = sum(nums);
        int target = s / 2;
        vector<bool> dp(target+1, false);
        vector<bool> next_dp(target+1, false);

        if (s % 2 == 1)
            return false;
        
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= 0; j--) {
                if (j >= nums[i]) {
                    dp[j] = dp[j] || dp[j-nums[i]];
                } 
            }
        }
        return dp[target];
    }
};
