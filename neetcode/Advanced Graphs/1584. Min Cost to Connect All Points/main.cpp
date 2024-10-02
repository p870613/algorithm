class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        vector<bool> visit(n);
        vector<int> min_dist(n, INT_MAX);
        int result = 0;

        min_dist[0] = 0;

        while (count < n) {
            int cur_node = -1;
            int cur_min_edge = INT_MAX;

            for (int i = 0; i < n; i++) {
                if (!visit[i] && min_dist[i] < cur_min_edge) {
                    cur_node = i;
                    cur_min_edge = min_dist[i];
                }
            }

            result += cur_min_edge;
            count ++;
            visit[cur_node] = true;

            for (int i = 0; i < n; i++) {
                int cost = abs(points[cur_node][0] - points[i][0]) +
                        abs(points[cur_node][1] - points[i][1]);
                if (!visit[i] && min_dist[i] > cost)
                    min_dist[i] = cost; 
            }
        }
        return result;
    }
};
