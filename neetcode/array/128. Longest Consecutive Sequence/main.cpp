class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ar;
        int ret = 0;

        ar.insert(nums.begin(), nums.end());
        
        for(int i: ar) {
            if(ar.find(i - 1) == ar.end()) {
                int len = 0;
                while(ar.find(i + len) != ar.end()) {
                    len ++;
                }  
                ret = max(ret, len);
            }
        }
        return ret;
    }
};
