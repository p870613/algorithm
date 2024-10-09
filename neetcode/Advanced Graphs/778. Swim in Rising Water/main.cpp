class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.size() == 1)
            return 0;

        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n));
        visit[0][0] = true;

        int result = max(grid[0][0], grid[n - 1][n - 1]);;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        pq.push({grid[0][0], 0, 0});
        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();

            result = max(result, cur[0]);

            for (int i = 0; i < 4; i++) {
                int x = cur[1] + dir[i][0];
                int y = cur[2] + dir[i][1];

                if (x < 0 || x >= n || y < 0 || y >= n || visit[x][y])
                    continue;
                if (x == n - 1 && y == n - 1)
                    return result;
                pq.push({grid[x][y], x, y});
                visit[x][y] = true;
            }
        }
        return -1;
    }
};
