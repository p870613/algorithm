struct node {
    bool word[26];
    struct node *next[26];
    bool flag;
};

class Solution {
public:
    struct node *root;
    vector<string> ret;
    void init(struct node *cur) {
        for (int i = 0; i < 26; i++) {
            cur->word[i] = false;
            cur->next[i] = NULL;
        }
        cur->flag = false;
    }
    void add(string word) {
        struct node *cur = root;

        for (int i = 0; i < word.size(); i++) {
            if (cur->word[word[i] - 'a'] == true) {
                cur = cur->next[word[i] - 'a'];
            } else {
                struct node *new_node = new node();
                init(new_node);
                cur->word[word[i] - 'a'] = true;
                cur->next[word[i] - 'a'] = new_node;
                cur = new_node;
            }
        }
        cur->flag = true;
    }

    bool check(struct node *cur, char c) {
        return cur->word[c - 'a'];
    }

    void dfs(struct node *cur, int r, int c, bool visit[][12], vector<vector<char>>& board, string word) {
        if (r < 0 || c < 0 || 
            r >= board.size() || c >= board[0].size() ||
            !check(cur, board[r][c]) || visit[r][c] == true)
            return;
        
        visit[r][c] = true;
        word = word + board[r][c];
        cur = cur->next[board[r][c] - 'a'];
       
        if (cur->flag == true && find(ret.begin(), ret.end(), word) == ret.end())
            ret.push_back(word);

        dfs(cur, r + 1, c, visit, board, word);
        dfs(cur, r - 1, c, visit, board, word);
        dfs(cur, r, c + 1, visit, board, word);
        dfs(cur, r, c - 1, visit, board, word);
        visit[r][c] = false;
    }

    void search(vector<vector<char>>& board) {
        bool visit[12][12] = {0};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                dfs(root, i, j, visit, board, "");
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new node();

        for (int i = 0; i < words.size(); i++)
            add(words[i]);

        search(board);
        return ret;
    }
};
