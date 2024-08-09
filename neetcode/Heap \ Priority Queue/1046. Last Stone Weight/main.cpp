class Solution {
public:
    
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int, vector<int>, less<int>> pq (stones.begin(), stones.end());

        while(pq.size() > 1) {
            int tmp1 = pq.top();
            pq.pop();
            int tmp2 = pq.top();
            pq.pop();

            if (tmp1 != tmp2)
                pq.push(tmp1 > tmp2?tmp1 - tmp2:tmp2 - tmp1);
        }
        return pq.empty() ? 0: pq.top();  
    }
};
