class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                int start = i - wordDict[j].size();
                if (start >= 0 && dp[start] == true &&
                    s.substr(start, wordDict[j].length()) == wordDict[j]) {
                        dp[i] = true;
                        break;
                }
            }
        }
        return dp[s.size()]; 
    }
};
