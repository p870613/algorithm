class LRUCache {
public:
    class Node {
        public:
        int key, val;
        Node *prev, *next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    Node *head, *tail;
    unordered_map<int, Node*> map;
    int cap;

    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    void move_to_head(int key) {
        Node *cur = map[key];
        
        if (cur == head->next)
            return;

        if(cur->prev)
            cur->prev->next = cur->next;
        if(cur->next)
            cur->next->prev = cur->prev;
    
        head->next->prev = cur;
        cur->next = head->next;
        head->next = cur;
        cur->prev = head;
    }

    int get(int key) {
        if (map.find(key) != map.end()) {
            move_to_head(key);
            return map[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node *cur = map[key];
            cur->val = value;
            move_to_head(key);
        } else {
            Node *cur = new Node(key, value);
            map[key] = cur;
            if(map.size() == 1) {
                head->next = cur;
                cur->prev = head;
                tail->prev = cur;
                cur->next = tail;
            } else {
                move_to_head(key);
            }
        }
        if (cap < map.size()) {
            Node *del = tail->prev;
            tail->prev = del->prev;
            del->prev->next = tail;
            del->next = NULL;
            del->prev = NULL;
            map.erase(del->key);
            delete del;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
