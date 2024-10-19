class Solution {
public:
    string ret = "";
    bool dfs(char ch, map <char, bool> &visit,
            map <char, vector<char>> &graph) {
        if (visit.find(ch) != visit.end())
            return visit[ch];
        
        visit[ch] = true;
        for (int i = 0; i < graph[ch].size(); i++) {
            if (dfs(graph[ch][i], visit, graph))
                return true;
        }
        visit[ch] = false;
        ret.push_back(ch);
        return false;
    }


    string foreignDictionary(vector<string>& words) {
        map <char, vector<char>> graph;
        map <char, bool> visit;

         for (const auto& word : words) {
            for (char ch : word) {
                graph[ch];
            }
        }

        for (size_t i = 0; i < words.size() - 1; ++i) {
            const string& w1 = words[i], & w2 = words[i + 1];
            size_t minLen = min(w1.length(), w2.length());
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }
            for (size_t j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].push_back(w2[j]);
                    break;
                }
            }
        }
        
        for (const auto& pair : graph) {
            if (dfs(pair.first, visit, graph)) {
                return "";
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;

    }
};
