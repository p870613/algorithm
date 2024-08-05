class Solution {
public:
    string map[8] = {"abc", "def", "ghi", "jkl", 
                    "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;

    void backtracking(string d, int index, string helper) {
        if (d.size() == index) {
            ret.push_back(helper);
            return;
        }

        for (int j = 0; j < map[d[index] - '0' - 2].size();  j++)
            backtracking(d, index + 1, helper + map[d[index]-'0'-2][j]);
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return ret;
        backtracking(digits, 0, "");
        return ret;
    }
};
