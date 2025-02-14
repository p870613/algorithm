class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur_max = 1, cur_min = 1, ret = 0;

        if (nums.size() == 1)
            return nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int tmp_cur_max = max(cur_max * nums[i], max(nums[i], cur_min * nums[i]));
            int tmp_cur_min = min(cur_max * nums[i], min(nums[i], cur_min * nums[i]));

            cur_max = tmp_cur_max;
            cur_min = tmp_cur_min; 
            if (cur_max > ret)
                ret = cur_max;
        }
        return ret;
    }

};
