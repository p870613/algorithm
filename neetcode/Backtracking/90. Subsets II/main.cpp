class Solution {
public:
    vector<vector<int>> ret;
    void backtracking(int start, vector<int>& ans, vector<int>& nums, bool *visit) {
        ret.push_back(ans);

        for (int i = start; i < nums.size(); i++) {
            if (visit[i] == true)
                continue;
            if (i > start && nums[i-1] == nums[i])
                continue;
            visit[i] = true;
            ans.push_back(nums[i]);
            backtracking(i+1, ans, nums, visit);
            ans.pop_back();
            visit[i] = false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        bool visit[10] = {false};
        vector<int> ans;

        sort(nums.begin(), nums.end());
        backtracking(0, ans, nums, visit);         
        return ret;
    }
};
