class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int l = 0, r = height.size()-1;

        while(l < r) {
            int area = (r - l) * min(height[r], height[l]);

            if(area > ret)
                ret = area;
            
            if (height[l] > height[r])
                r --;
            else 
                l ++;
        }
        return ret;
    }
};
