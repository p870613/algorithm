class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        
        if (intervals.size() == 0) {
            ret.push_back(newInterval);
            return ret;
        }

        for (int i = 0; i < intervals.size(); i++) {
            if(newInterval[1] < intervals[i][0]) {
                ret.push_back(newInterval);
                for (; i < intervals.size(); i++)
                    ret.push_back(intervals[i]);
                return ret;
            } else if (newInterval[0] > intervals[i][1]) {
                ret.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        ret.push_back(newInterval);
        return ret;
    }
};
