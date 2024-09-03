class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int cur_max = 0;

        for (int i = 0; i < nums.size(); i++) {
            cur_max = cur_max + nums[i];
            
            if (ret < cur_max)
                ret = cur_max;
            
            if (cur_max < 0)
                cur_max = 0;
        }
        return ret;
    }
};
