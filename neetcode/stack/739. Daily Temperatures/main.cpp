class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector <int> ret(temperatures.size(), 0);
        vector <int> sta;

        for(int i = 0; i < temperatures.size(); i ++) {
            while(true) {
                if(sta.size() != 0 && temperatures[sta.back()] < temperatures[i]) {
                    ret[sta.back()] = i - sta.back();
                    sta.pop_back();
                } else {
                    sta.push_back(i);
                    break;
                }
            }
        }
        return ret;
    }
};
