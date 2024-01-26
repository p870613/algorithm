int jump(int* nums, int numsSize) {
    int dp[numsSize];

    for(int i = 0; i < numsSize; i++)
        dp[i] = 0;

    for(int i = 0; i < numsSize; i++) {
        for(int j = 1; j <= nums[i]; j++) {
            if(i + j < numsSize) {
                if(dp[i + j] > dp[i] + 1 || dp[i+j] == 0)
                    dp[i + j] = dp[i] + 1;
            }
        }
        
    }
    return dp[numsSize-1];
}
