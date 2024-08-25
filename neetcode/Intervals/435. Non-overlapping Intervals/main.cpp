class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ret = 0;
        int prev_end = intervals[0][1]; 

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start >= prev_end) {
                prev_end = end;
            } else {
                ret ++;
                prev_end = min(end, prev_end);
            }
        }
        return ret;
    }
};
