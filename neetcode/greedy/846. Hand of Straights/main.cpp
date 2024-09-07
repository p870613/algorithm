class Solution {
public:
    class cmp {
        public:
        bool operator()(pair<int, int> *a, pair<int, int> *b) {
            return a->first < b->first;
        }
    };
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        
        map<int, int> m;

        for (int i = 0; i < hand.size(); i++)
            m[hand[i]] ++;
        
        while (!m.empty()) {
            int cur = m.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (m[cur + i] == 0) {
                    return false;
                }
                m[cur + i] --;
                if (m[cur + i] < 1) {
                    m.erase(cur + i);
                }
            }
        }
        return true;
    }
};
