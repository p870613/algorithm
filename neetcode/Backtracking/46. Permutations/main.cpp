class Solution {
public:
    vector<vector<int>> ret;
    void backtracking(vector<int>&ans, vector<int>& nums, bool *visit) {
        if (ans.size() == nums.size()) {
            ret.push_back(ans);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visit[i] == true)
                continue;
            visit[i] = true;
            ans.push_back(nums[i]);
            backtracking(ans, nums, visit);
            ans.pop_back();
            visit[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        bool visit[6] = {false};
        vector<int> ans;
        backtracking(ans, nums, visit);
        return ret;
    }
};
