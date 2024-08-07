class Solution {
public:
    vector<vector<string>> ret;
    void backtracking(vector<string>& board, int r, set<int>& col, set<int>& post, set<int>& neg, int n) {
        if (r == n) {
            ret.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col.find(c) != col.end() || post.find(r+c) != post.end()
                || neg.find(r-c) != neg.end())
                continue;
            col.insert(c);
            post.insert(r+c);
            neg.insert(r-c);
            board[r][c] = 'Q';
            backtracking(board, r + 1, col, post, neg, n);

            post.erase(r+c);
            neg.erase(r-c);
            col.erase(c);
            board[r][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        set<int> col;
        set<int> post;
        set<int> neg;
        vector<string> board(n);
        string t(n, '.');

        for (int i = 0; i < n; i++)
            board[i] = t;

        backtracking(board, 0, col, post, neg, n);
        return ret;
    }
};
