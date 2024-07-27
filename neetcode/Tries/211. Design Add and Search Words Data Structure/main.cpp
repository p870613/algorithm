struct node {
    bool word[26];
    bool flag;
    struct node *next[26];
};

class WordDictionary {
public:
    struct node *root;
    WordDictionary() {
        root = new node();
        for (int i = 0; i < 26; i++) {
            root->word[i] = false;
            root->next[i] = NULL;
        }
        root->flag = false;
    }
    
    void addWord(string word) {
        struct node *cur = root;

        for (int i = 0; i < word.size(); i++) {
            if (cur->word[word[i]-'a'] == NULL) {
                struct node *new_node = new node();

                for (int j = 0; j < 26; j++) {
                    new_node->word[j] = false;
                    new_node->next[j] = NULL;
                }
                new_node->flag = false;
                cur->next[word[i]-'a'] = new_node;
                cur->word[word[i]-'a'] = true;
            }
            cur = cur->next[word[i]-'a'];
        }
        cur->flag = true;
    }
    
    bool check(struct node* cur) {
        for (int i = 0; i < 26; i++)
            if (cur->word[i] == true &&
                cur->next[i]->flag == true)
                return true;
        return false;
    }
    bool dfs(string word, int index, struct node* cur) {
        for (int i = index; i < word.size(); i++) {
            if (word[i] == '.') {
                if (i == word.size() - 1 && check(cur) == true)
                    return true;
                for (int j = 0; j < 26; j++) {
                    if ((cur->word[j] == true && 
                        dfs(word, i + 1, cur->next[j]) == true)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (cur->word[word[i] - 'a'] == true) {
                    cur = cur->next[word[i] - 'a'];
                } else {
                    return false;
                }
            }
        }            
        return cur->flag;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
