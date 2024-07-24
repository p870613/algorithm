struct node {
    bool word[26];
    bool flag;
    struct node *next[26];
};

class Trie {
public:
    struct node *root;
    Trie() {
        root = new node();
        for (int i = 0; i < 26; i++) {
            root->word[i] = false;
            root->next[i] = NULL;
        }
        root->flag = false;
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        struct node *cur = root;

        for (int i = 0; i < word.size(); i++) {
            if (cur->word[word[i] - 'a'] == NULL)
                return false;
            cur = cur->next[word[i] - 'a'];
        }
        if (cur->flag == true)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) {
        struct node *cur = root;

        for (int i = 0; i < prefix.size(); i++) {
            if (cur->word[prefix[i] - 'a'] == NULL)
                return false;
            cur = cur->next[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
