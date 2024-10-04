class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <pair<int, int>> map[n];
        int count = 0;
        queue<pair<int, int>>q;        
        vector<int> dis(n, INT_MAX);

        for (int i = 0; i < flights.size(); i++) {
            int s = flights[i][0];
            int d = flights[i][1];
            int t = flights[i][2];
            map[s].push_back({d, t});
        }

        dis[src] = 0;

        q.push({src, 0});
        
        while (!q.empty()) {
            int len = q.size();

            if (count > k)
                break;
            
            for (int i = 0; i < len; i++) {
                int cur_node = q.front().first;
                int cur_cost = q.front().second;

                q.pop();

                for (int i = 0; i < map[cur_node].size(); i++) {
                    int next_node = map[cur_node][i].first;

                    if (cur_cost + map[cur_node][i].second < dis[next_node]) {
                        q.push({next_node, cur_cost + map[cur_node][i].second});
                        dis[next_node] = cur_cost + map[cur_node][i].second;
                    }
                }
            }
            count ++;
        }
        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};
