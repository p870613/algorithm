class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> sta;

        for(int i = 0; i < s.size(); i++) {
            if(sta.size() != 0 && sta.back().first == s[i]) {
                int count = sta.back().second;
                
                if(count == k-1) {
                    sta.pop_back();
                } else {
                    sta.back().second ++;
                }
                
            } else {
                sta.push_back(make_pair(s[i], 1));
            }
        }
        string ret = "";
        for(int i = 0; i < sta.size(); i++)
            ret = ret + string(sta[i].second, sta[i].first);
        return ret;
    }
};
