class Solution {
public:
    bool is_alp_number(char c) {
        if((c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9'))
           return true;
        return false;
    }

    char lowercase(char c) {
        if((c >= 'a' && c <= 'z') ||
           (c >= '1' && c <= '9'))
           return c;
        return c + 32; 
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.size();

        while(r > l) {
            while(r > l && !is_alp_number(s[l]))
                l ++;
            while(r > l && !is_alp_number(s[r]))
                r --;
            if(lowercase(s[l]) != lowercase(s[r]))
                return false;
            l ++;
            r --;
        }
        return true;
    }
};
