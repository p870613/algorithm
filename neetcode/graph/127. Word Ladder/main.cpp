class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        queue<string> q;
        int result = 1;

        for (int i = 0; i < wordList.size(); i++)
            dict.insert(wordList[i]);

        q.push(beginWord);
        while (!q.empty()) {
            int len = q.size();
        
            for (int i = 0; i < len; i++) {
                string w = q.front();
                q.pop();
                
                if (w == endWord)
                    return result;
                
                for (int j = 0; j < w.size(); j++) {
                    char c = w[j];
                    for (int k = 0; k < 26; k++) {
                        w[j] = k + 'a';
                        if (dict.find(w) != dict.end()) {
                            q.push(w);
                            dict.erase(w);
                        }
                    }
                    w[j] = c;
                }
            }
            result ++;
        }
        return 0;
    }
};
