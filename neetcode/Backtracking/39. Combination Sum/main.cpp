class Solution {
public:
    vector<vector<int>> ret;
    void backtracking(vector<int> &ans, int start, int cur, vector<int>& can, int target) {
        if (cur == target) {
            ret.push_back(ans);
            return;
        } else if (cur > target) {
            return;
        }

        for (int i = start; i < can.size(); i++) {
            ans.push_back(can[i]);
            backtracking(ans, i, cur + can[i], can, target);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        backtracking(ans, 0, 0, candidates, target);
        return ret;      
    }
};
