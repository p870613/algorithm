class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(r >= l) {
            int m = l + (r - l) / 2;
            
            if(target == nums[m])
                return m;

            if(nums[m] >= nums[l]) {
                if(target >= nums[l] && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else { 
                if(target > nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            } 
        } 
        return -1;
    }
};
