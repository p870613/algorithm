class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> win;
        int start = 0, end = 0;
        
        if (nums.size() == 1) {
            ret.push_back(nums[0]);
            return ret;
        }

        while (end < nums.size()) {
            while (win.size() != 0 && nums[win.back()] < nums[end])
                win.pop_back();
            win.push_back(end);
            end ++;

            if (end - start == k) {
                ret.push_back(nums[win.front()]);
                if(win.front() <= start)
                    win.pop_front();
                start ++;
            }
        }
        return ret;
    }
};
