class Solution {
public:
    long long cal_h (vector<int>& p, int k) {
        long long sum = 0;
        for (int i = 0; i < p.size(); i++) {
            sum = sum + p[i] / k;
            sum = (p[i] % k == 0) ? sum: sum+1;
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ret = 1e9;
        int l = 1, r = 0;

        for (int i = 0; i < piles.size(); i++)
            if (piles[i] > r)
                r = piles[i];
        
        while(r >= l) {
            int m = l + (r - l) / 2;
            long long tmp = cal_h(piles, m);

            if (tmp > (long long)h) {
                l = m + 1;
            } else {
                ret = ret > m ? m : ret;
                r = m - 1;
            }
        }
        return ret;
    }
};
