class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        int pre = 1, post = 1;
        
        for(int i = 0; i < nums.size()-1; i++) {
            pre = pre * nums[i];
            ret[i+1] = pre;
        }

        for(int i = nums.size()-1; i > 0 ; i--) {
            post = post * nums[i];
            ret[i-1] = ret[i-1] * post; 
        }
       
        return ret;
    }
};
