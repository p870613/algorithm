class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int m = 1e9;

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] - m > ret)
                ret = prices[i] - m;
            if(prices[i] < m)
                m = prices[i];
        }
        return ret;
    }
};
