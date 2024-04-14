class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        int l = 0, r = height.size() - 1;
        int lmax = height[l], rmax = height[r];

        while (r > l) {
            if(rmax > lmax) {
                lmax = max(height[++l], lmax);
                ret = ret + lmax - height[l];
            } else {
                rmax = max(height[--r], rmax);
                ret = ret + rmax - height[r];
            }
        }
        
        return ret;
    }
};
