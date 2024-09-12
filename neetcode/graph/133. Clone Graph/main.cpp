/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        unordered_map <Node*, Node*> m;
        Node *copy = new Node(node->val);
        queue<Node*> q;

        m[node] = copy;
        q.push(node);

        while(!q.empty()) {
            Node *cur = q.front();
            q.pop();

            for (int i = 0; i < cur->neighbors.size(); i++) {
                Node* n = cur->neighbors[i];

                if (m.find(n) == m.end()) {
                    m[n] = new Node(n->val);
                    q.push(n);
                }
                m[cur]->neighbors.push_back(m[n]);
            }
        }
        return copy;
    }
};
