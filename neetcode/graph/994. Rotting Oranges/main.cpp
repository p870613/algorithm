class Solution {
public:
    bool check(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ret = 0;
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j));

        while (!q.empty()) {
            int len = q.size();
            bool flag = false;

            for (int i = 0; i < len; i++) {
                int cur_i = q.front().first;
                int cur_j = q.front().second;
                
                q.pop();
                if (cur_i + 1 < m && grid[cur_i + 1][cur_j] == 1) {
                    q.push(make_pair(cur_i + 1, cur_j));
                    grid[cur_i + 1][cur_j] = 2;
                    flag = true;
                }
                    
                if (cur_i - 1 >= 0 && grid[cur_i - 1][cur_j] == 1) {
                    q.push(make_pair(cur_i - 1, cur_j));
                    grid[cur_i - 1][cur_j] = 2;
                    flag = true;
                }

                if (cur_j + 1 < n && grid[cur_i][cur_j + 1] == 1) {
                    q.push(make_pair(cur_i, cur_j + 1));
                    grid[cur_i][cur_j + 1] = 2;
                    flag = true;
                }
                if (cur_j - 1 >= 0 && grid[cur_i][cur_j - 1] == 1) {
                    q.push(make_pair(cur_i, cur_j - 1));
                    grid[cur_i][cur_j - 1] = 2;
                    flag = true;
                }
            }
            if (flag)
                ret ++;
        }

        return check(grid) == true ? -1 : ret;
    }
};
