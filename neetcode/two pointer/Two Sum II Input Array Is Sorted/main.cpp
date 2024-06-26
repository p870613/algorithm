class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int l = 0, r = numbers.size() - 1;

        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if(sum == target) {
                ret.push_back(l + 1);
                ret.push_back(r + 1);
                break; 
            } else if(sum > target)
                r --;
            else
                l ++;
        }
        return ret;
    }
};
