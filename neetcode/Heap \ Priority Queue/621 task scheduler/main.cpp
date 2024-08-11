class Solution {
public:
    class cnt {
        public:
        int count;
        char ch;
        cnt (char c) {
            this->count = 0;
            this->ch = c;
        }
    };
    class cmp {
        public:
        bool operator()(cnt* cl, cnt* c2){
            return cl->count < c2->count;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {
        vector<cnt*> ar;
        priority_queue <cnt*, vector<cnt*>, cmp> pq;

        for (int i = 0;i < 26; i++)
            ar.push_back(new cnt('A' + i));
        for (int i = 0; i < tasks.size(); i++)
            ar[tasks[i] - 'A']->count ++;
        
        for (int i = 0; i < 26; i++)
            if (ar[i]->count)
                pq.push(ar[i]);

        ar.clear(); 
        int ret = 0;
        while (!pq.empty()) {
            for (int i = 0; i <= n && (!ar.empty() || !pq.empty()); i++) {
                if (!pq.empty()) {
                    cnt *tmp = pq.top();
                    pq.pop();
                    tmp->count --;
                    if (tmp->count > 0)
                        ar.push_back(tmp);
                }
                ret ++;
            }
            for (int i = 0; i < ar.size(); i++)
                pq.push(ar[i]);
            ar.clear();
        }
        return ret;
    }
};