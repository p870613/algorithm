class Solution {
public:
    
    void backtracking(int l, int r, string str, vector<string>&ret, int count){
        if(l == count && r == count) {
            ret.push_back(str);
            return;
        }

        if(l < count)
            backtracking(l + 1, r, str + "(", ret, count);
        if(r < count && l > r)
            backtracking(l, r + 1, str + ")", ret, count);
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        backtracking(0, 0, "", ret, n);
        return ret;    
    }
};
