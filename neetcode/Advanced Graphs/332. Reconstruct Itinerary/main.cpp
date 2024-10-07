class Solution {
public:
    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &map,
            string src, vector <string>&ret) {
        
        while (!map[src].empty()) {
            string next = map[src].top();
            map[src].pop();
            dfs(map, next, ret);
        }
        ret.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector <string> ret;
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> map;
        int count = 0;

        for (int i = 0; i < tickets.size(); i++) {
            map[tickets[i][0]].push(tickets[i][1]);
        }
        dfs(map, "JFK", ret);
        reverse(ret.begin(), ret.end());
        return ret;
    
    }
};
