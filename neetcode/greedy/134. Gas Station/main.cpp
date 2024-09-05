class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> ar;
        int sum = 0;
        int ret = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            sum = sum + gas[i] - cost[i];
            ar.push_back(gas[i] - cost[i]);
        }

        if (sum < 0)
            return -1;

        sum = 0;
        for (int i = 0; i < ar.size(); i++) {
            sum = sum + ar[i];
            if (sum < 0) {
                sum = 0;
                ret = i + 1;
            }    
        }
        return ret;
    }
};
