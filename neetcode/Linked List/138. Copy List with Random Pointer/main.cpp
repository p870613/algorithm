/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        unordered_map<Node*, Node*> addr;

        while (cur != NULL) {
            Node* new_node = new Node(cur->val);
            addr[cur] = new_node;
            cur = cur->next;
        }

        cur = head;
        while(cur != NULL) {
            Node *copy = addr[cur];
            copy->next = addr[cur->next];
            copy->random = addr[cur->random];
            cur = cur->next;
        }
        return addr[head];
    }
};
