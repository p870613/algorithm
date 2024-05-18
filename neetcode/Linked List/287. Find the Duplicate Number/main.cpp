class Solution {
public:
    int move(vector<int>& nums, int index) {
        return nums[index];
    }

    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        int ret = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }

        slow = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast)
                break;
        }

        return slow;
    }
};
