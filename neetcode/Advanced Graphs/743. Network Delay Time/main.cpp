class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> map[n+1];

        for (int i = 0; i < times.size(); i++) {
            int source = times[i][0];
            int dest = times[i][1];
            int time = times[i][2];
            map[source].push_back({time, dest});
        }
            
        vector<int> recievetime(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        recievetime[k] = 0;

        while (!pq.empty()) {
            int cur_node = pq.top().second;
            int cur_time = pq.top().first;

            pq.pop();
            for (int i = 0; i < map[cur_node].size(); i++) {
                int next_node = map[cur_node][i].second;
                int time = map[cur_node][i].first;

                if (cur_time > recievetime[next_node])
                    continue;

                if (recievetime[next_node] > cur_time + time) {
                    recievetime[next_node] = cur_time + time;
                    pq.push({recievetime[next_node], next_node});
                }
            }
        }
        int result = INT_MIN;
        for (int i = 1; i <= n; i++)
            result = max(result, recievetime[i]);

        return result == INT_MAX ? -1 : result;
    }
};
