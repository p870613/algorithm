class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> map_s;
        unordered_map<char, int> map_t;
        int score_s = 0; 
        int start = 0, end = 0;
        int start_index = 0, len = 1e9;

        if (t.size() > s.size())
            return "";

        for (int i = 0; i < t.size(); i++)
            map_t[t[i]] ++;

        while (end >= start) {
            if (score_s == map_t.size() || end == s.size()) {
                
                if (score_s == map_t.size() && 
                    (len > (end - start))) {
                        start_index = start;
                        len = end - start;
                }
                    
                if (map_t.find(s[start]) != map_t.end()) {
                    map_s[s[start]] --;
                    if (map_s[s[start]] < map_t[s[start]])
                        score_s --;
                }
                start ++;
            } else {
                if (map_t.find(s[end]) != map_t.end()) {
                    map_s[s[end]] ++;
                    if (map_s[s[end]] - 1 < map_t[s[end]] && map_s[s[end]] >= map_t[s[end]])
                        score_s ++;
                }
                end ++;
            }
        }
        return len == 1e9 ? "" :s.substr(start_index, len);
    }
};
