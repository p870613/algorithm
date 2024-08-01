class Solution {
public:
    vector<vector<int>> ret;
    void backtracking(int start, int num, vector<int>& ans, vector<int>& nums, bool *visit) {
        if (num == ans.size()) {
            ret.push_back(ans);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (visit[i] == true)
                continue;
            visit[i] = true;
            ans.push_back(nums[i]);
            backtracking(i, num, ans, nums, visit);
            ans.pop_back();
            visit[i] = false;
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        bool visit[10] = {false};
        vector<int> ans;

        ret.push_back(ans);
        for (int i = 0; i < nums.size(); i++)
            backtracking(0, i+1, ans, nums, visit);     
        return ret;
    }
};
