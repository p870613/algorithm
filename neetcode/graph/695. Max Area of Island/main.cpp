class Solution {
public:
    void dfs(vector<vector<int>>& grid, int &num, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return;
        
        num ++;
        grid[i][j] = 0;
        dfs(grid, num, i + 1, j, m, n);
        dfs(grid, num, i - 1, j, m, n);
        dfs(grid, num, i, j + 1, m, n);
        dfs(grid, num, i, j - 1, m, n);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0, num = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, num, i, j, m, n);
                    if (ret < num)
                        ret = num;
                    num = 0;
                }
            }
        }
        return ret;
    }
};
