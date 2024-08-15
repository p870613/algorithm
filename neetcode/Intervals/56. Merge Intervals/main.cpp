class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;

        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (i > 0 && intervals[i][0] >= intervals[i-1][0] && intervals[i][0] <= intervals[i-1][1]) {
                intervals[i][0] = min(intervals[i-1][0], intervals[i][0]);
                intervals[i][1] = max(intervals[i-1][1], intervals[i][1]);
                ret.pop_back();
                ret.push_back(intervals[i]);
            } else {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};
