#define INF 2147483647
class Solution {
public:
    void dfs(int i, int j, int m, int n, int depth, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
            return;
        if (depth > grid[i][j])
            return;

        if (grid[i][j] == INF || grid[i][j] > depth)
            grid[i][j] = depth;

        dfs(i+1, j, m, n, depth+1, grid);
        dfs(i-1, j, m, n, depth+1, grid);
        dfs(i, j+1, m, n, depth+1, grid);
        dfs(i, j-1, m, n, depth+1, grid);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    dfs(i, j, m, n, 0, grid);
                }
            }
        }
    }
};
