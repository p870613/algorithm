class Compare {
public:
    bool operator()(vector<int> a, vector<int> b)
    {
        if (a[0]*a[0]+a[1]*a[1] > b[0]*b[0]+b[1]*b[1])
            return true;
        return false;
    }
};
class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <vector<int>, vector<vector<int>>, Compare> pq(points.begin(), points.end()) ;
        vector<vector<int>> ret;

        for (int i = 0; i < k; i++) {
            ret.push_back(pq.top());
            pq.pop();
        }
            
        return ret;
    }
};
