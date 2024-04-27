class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        int start;
        vector<pair<int, int>> sta;

        for(int i = 0; i < heights.size(); i++) {
            start = i;
            while(sta.size() != 0 && sta.back().second > heights[i]) {
                ret = max(ret, sta.back().second * (i - sta.back().first));
                start = sta.back().first;
                sta.pop_back();
            }
            sta.push_back(make_pair(start, heights[i]));
        }

        for(int i = 0; i < sta.size(); i++) {
            int a = sta[i].second*(heights.size()-sta[i].first);
            ret = max(ret,a);
        }

        return ret;
    }
};
