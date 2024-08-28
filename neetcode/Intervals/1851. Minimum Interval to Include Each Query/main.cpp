class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ret;
        vector<int> s_q = queries;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> m;

        sort(intervals.begin(), intervals.end());
        sort(s_q.begin(), s_q.end());

        int j = 0;
        for (int i = 0; i < queries.size(); i++) {
            int query = s_q[i];

            while (j < intervals.size() && intervals[j][0] <= query) {
                int left = intervals[j][0];
                int right = intervals[j][1];
                pq.push({right - left + 1, right});
                j++;
            }

            while(!pq.empty() && pq.top().second < query) {
                // printf("%d %d\n", pq.top().second - pq.top().first + 1, pq.top().second);
                pq.pop();
            }
            // printf("== %d %d == \n", pq.top().second - pq.top().first + 1, pq.top().second);
            if (pq.empty())
                m[query] = -1;
            else
                m[query] = pq.top().first;
        }

        for (int i = 0; i < queries.size(); i++)
            ret.push_back(m[queries[i]]);
        return ret;
    }
};
