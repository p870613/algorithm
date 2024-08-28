/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector <int> start, end;
        int ret = 0, count = 0;
        int s = 0, e = 0;

        for (int i = 0; i < intervals.size(); i++) {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        while (s < intervals.size()) {
           
            if (start[s] < end[e]) {
                count ++;
                s ++;
            } else {
                e ++;
                count --;
            }
            ret = max(ret, count);
        }
        return ret;
    }
};
