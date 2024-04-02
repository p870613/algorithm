class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> freq(nums.size());
        vector<int> ret;
        
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]] ++;
        
        for(auto item: mp)
            freq[item.second-1].push_back(item.first);
        
        for(int i = freq.size()-1; i >= 0 ; i--) {
            for(int j = 0; j < freq[i].size(); j++)
                ret.push_back(freq[i][j]);
            if(ret.size() >= k)
                break;
        }
              
        return ret;
    }
};
