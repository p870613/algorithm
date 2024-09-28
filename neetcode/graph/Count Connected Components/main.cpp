class Solution {
public:
    void dfs (int &ret, int cur, unordered_map <int,vector<int>> &map,
              unordered_map <int, int> &visit, bool flag) {
        if (visit.find(cur) != visit.end())
            return;

        if (flag == false)
            ret ++;
        visit[cur] = ret;

        for (int i = 0; i < map[cur].size(); i++)
            dfs(ret, map[cur][i], map, visit, true);
            
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map <int, vector<int>> map;
        unordered_map <int, int> visit;
        int ret = 0;

        for (int i = 0; i < edges.size(); i++) {
            map[edges[i][0]].push_back(edges[i][1]);
            map[edges[i][1]].push_back(edges[i][0]);
        }
            
        for (int i = 0; i < n; i++) {
            dfs(ret, i, map, visit, false);
        }

        return ret;
    }
};
