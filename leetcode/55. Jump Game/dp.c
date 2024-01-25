bool canJump(int* nums, int numsSize) {
    int dp[numsSize];
    int j = numsSize - 1;
    for(int i = 0; i < numsSize; i++)
        dp[i] = false;

    dp[j] = true;
    for(int i = numsSize - 1; i >= 0; i--) {
        if(i + nums[i] >= j) {
            dp[i] = true;
            j = i;
        }
    }
    return dp[0];
}
