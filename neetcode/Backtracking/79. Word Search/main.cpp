class Solution {
public:
    bool ret;
    void backtracking(vector<vector<char>>& board, string word, int r, int c, bool visit[][6], int index) {
        if (r >= 0 && c >= 0 && r < board.size() && c < board[0].size() && !visit[r][c]) {
            if (index == word.size() - 1 && board[r][c] == word[index]) {
                ret = true;
                return;
            } else if (board[r][c] == word[index]) {
                visit[r][c] = true;
                backtracking(board, word, r + 1, c, visit, index + 1);
                backtracking(board, word, r - 1, c, visit, index + 1);
                backtracking(board, word, r, c + 1, visit, index + 1);
                backtracking(board, word, r, c - 1, visit, index + 1);
                visit[r][c] = false;
            }
        } else {
            return;
        }
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool visit[6][6] = {false};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0])
                    backtracking(board, word, i, j, visit, 0);
            }
        }
        return ret;
    }
};
