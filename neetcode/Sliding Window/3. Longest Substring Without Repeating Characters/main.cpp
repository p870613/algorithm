class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0;
        int ret = 0;
        unordered_map <char, int> map;

        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] == 0) {
                map[s[end]] ++;
                end ++;  
            } else {
                if(end - start > ret)
                    ret = end - start;
                map[s[start]] --;
                start ++;
                i --;     
            }
        }
      
        if (end - start > ret)
            ret = end - start;
        return ret;
    }
};
