class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int ret = 1e9;

        while (r >= l) {
            int m = l + (r - l) / 2; 
            if(nums[m] >= nums[l]) {
                ret = min(nums[l], ret);
                l = m + 1;
            } else {
                ret = min(nums[m], ret);
                r = m - 1;
            }  
        }
        return ret;
    }
    
};
