class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> p(m, vector<bool>(n));
        vector<vector<bool>> a(m, vector<bool>(n));
        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            dfs(heights, p, i, 0, m, n);
            dfs(heights, a, i, n - 1, m, n);
        }

        for (int i = 0; i < n; i++) {
            dfs(heights, p, 0, i, m, n);
            dfs(heights, a, m - 1, i, m, n);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][j] && a[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>& h, vector<vector<bool>>& v, int i, int j, int m, int n) {
        v[i][j] = true;

        if (i > 0 && v[i-1][j] == false && h[i-1][j] >= h[i][j])
            dfs(h, v, i - 1, j, m, n);
        if (i < m - 1 && v[i+1][j] == false && h[i+1][j] >= h[i][j])
            dfs(h, v, i + 1, j, m, n);
        if (j > 0 && v[i][j-1] == false && h[i][j-1] >= h[i][j])
            dfs(h, v, i, j-1, m, n);
        if (j < n - 1&& v[i][j+1] == false && h[i][j+1] >= h[i][j])
            dfs(h, v, i, j+1, m, n);
    }
};
