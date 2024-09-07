class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ret;
        map<char, int> map;
        int size = 1, end = 0;

        for (int i = 0; i < s.size(); i++)
            map[s[i]] = i;
        
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] > end)
                end = map[s[i]];

            if (end == i) {
                ret.push_back(size);
                size = 0;
            }
            size ++;
        }
        return ret;
    }
};