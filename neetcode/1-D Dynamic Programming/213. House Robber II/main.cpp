class Solution {
public:
    int rob1(vector<int>& nums, int start, int end) {
        int prev = 0;
        int cur = 0;
        int next = 0;

        for (int i = start; i <= end; i++) {
            next = max(prev + nums[i], cur);
            prev = cur;
            cur = next;
        }
        return cur;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(rob1(nums, 0, n - 2), rob1(nums, 1, n - 1));
    }
};
