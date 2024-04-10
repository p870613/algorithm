class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            int sum;
            
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            while (k > j) {
                sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    while(k > j && nums[k] == nums[k-1])
                        k --;
                    while(k > j && nums[j] == nums[j+1])
                        j ++;
                    
                    k --;
                    j ++;
                } else if(sum > 0) {
                    k --;
                } else {
                    j ++;
                }   
            }
        }
        return ret;
    }
};
