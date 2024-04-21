class Solution {
public:
    static bool cmp(pair<int, int>a, pair<int, int>b) {
        return a.first > b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> p;
        vector<float> stack;
        int len;

        for(int i = 0; i < speed.size(); i++)
            p.push_back(make_pair(position[i], speed[i]));

        sort(p.begin(), p.end(), cmp);

        for(int i = 0; i < p.size(); i++) {    
            stack.push_back(((float)target - p[i].first) / p[i].second);
            len = stack.size();
            if(len >= 2 && stack[len-1] <= stack[len-2])
                stack.pop_back();
        }
        return stack.size();
    }
};
