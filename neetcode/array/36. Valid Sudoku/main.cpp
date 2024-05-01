class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> sqa(9);

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.')
                    continue;

                int sqa_index = (i/3)*3 + j / 3;
                if(row[i].find(board[i][j]) != row[i].end() ||
                   col[j].find(board[i][j]) != col[j].end() ||
                   sqa[sqa_index].find(board[i][j]) != sqa[sqa_index].end())
                   return false;
                
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                sqa[sqa_index].insert(board[i][j]);
            }
        }
        return true;
            
    }
};
