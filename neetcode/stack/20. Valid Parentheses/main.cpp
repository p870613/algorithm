class Solution {
public:
    bool isValid(string s) {
        int count = 0;
        vector<char> c;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                count ++;
                c.push_back(s[i]);
            } else {
                count --;
                if(count < 0 || ((s[i] >> 4) != (c[c.size()-1])>>4)) {
                    return false;
                } else {
                    c.pop_back();
                }
            } 
        }
        if(count == 0)
            return true;
        return false;
    }
};
