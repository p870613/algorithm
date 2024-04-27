class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last_index[26] = {0};
        bool seen[26] = {false};
        vector<char> sta;
        string ret = "";

        for(int i = 0; i < s.size(); i++) {
            last_index[s[i] -'a'] = i;
        }
        
        for(int i = 0; i < s.size(); i++) {
            if(seen[s[i]-'a'])
                continue;
              
            while(sta.size() != 0 && sta.back() > s[i] && last_index[sta.back()-'a'] > i) {

                seen[sta.back()-'a'] = false;
                sta.pop_back();
                
            }
            sta.push_back(s[i]);
            
            seen[s[i]-'a'] = true;


        }

        for(int i = 0; i < sta.size(); i++)
            ret = ret + sta[i];
        // cout << ret << endl; 
        return ret; 
    }
};
