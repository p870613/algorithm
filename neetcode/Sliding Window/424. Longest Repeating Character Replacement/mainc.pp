class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret = 0;
        int start = 0, end = 0;
        int max_frq = 0;
        int map[26] = {0};

        for (end = 0; end < s.size(); end++) {
            map[s[end] - 'A'] ++;
            max_frq = max(max_frq, map[s[end] - 'A']);
        
            if ((end - start + 1) - max_frq > k) {
                map[s[start] - 'A'] --;
                start ++;
            } else {
                ret = max(ret, (end - start + 1));
            }
        }
        return ret;
    }
};
