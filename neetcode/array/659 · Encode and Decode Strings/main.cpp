class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string ret = "";
        for(auto str:strs) {
            ret = ret + to_string(str.size()) + "#" +str;
        }
        return ret;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> ret;
        int i = 0, j = 0;
        int len;

        while(i < str.size()) {
            j = i;
            while(str[j] != '#')
                j++;
            len = stoi(str.substr(i, j-i));
            ret.push_back(str.substr(j+1, len));
            i = j + 1 + len;
        }
        return ret;
    }
};
