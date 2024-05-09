class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map1[26] = {0}, s1_len = s1.size();
        int map2[26] = {0}, s2_len = s2.size() ;
        int start = 0, end = s1_len;

        if (s1_len > s2_len)
            return false;

        for(int i = 0; i < s1_len; i++) {
            map1[s1[i] - 'a'] ++;
            map2[s2[i] - 'a'] ++;
        }
        if(!memcmp(map1, map2, 26 * sizeof(int)))
            return true;
        for(; end < s2_len; start ++, end ++) {
            map2[s2[start] - 'a'] --;
            map2[s2[end] - 'a'] ++;
            if(!memcmp(map1, map2, 26 * sizeof(int)))
                return true;
        }
        return false;
    }
};
