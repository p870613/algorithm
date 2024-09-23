class Solution {
public:
    int find(int node, unordered_map <int, int> &par) {
        if (par[node] == node)
            return node;
        else
            return find(par[node], par);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map <int, int> par;
        int n = edges.size();

        for (int i = 0; i < n; i++)
            par[i+1] = i+1;

        for (int i = 0; i < n; i++) {
            int par1 = find(edges[i][0], par);
            int par2 = find(edges[i][1], par);

            if (par1 != par2)
                par[par2] = par1;
            else
                return {edges[i][0], edges[i][1]};              
        }
        return {};
    }
};
