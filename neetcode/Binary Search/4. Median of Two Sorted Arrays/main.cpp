class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        int target = size / 2;
        if (size % 2 == 1 || target == 0)
            return find_median_index(nums1, nums2, target);
        else
            return (find_median_index(nums1, nums2, target) + find_median_index(nums1, nums2, target - 1)) / 2.0;
    }

    int find_median_index(vector<int>& nums1, vector<int>& nums2, int target) {
        int nums1_l = 0, nums1_r = nums1.size() - 1;
        int nums2_l = 0, nums2_r = nums2.size() - 1;

        while (true) {
            if(nums1_l > nums1_r) 
                return nums2[target-nums1_l];
            if(nums2_l > nums2_r)
                return nums1[target-nums2_l];
            int nums1_m = nums1_l + (nums1_r - nums1_l) / 2;
            int nums2_m = nums2_l + (nums2_r - nums2_l) / 2;

            if (nums1_m + nums2_m < target) {
                if(nums1[nums1_m] > nums2[nums2_m])
                    nums2_l = nums2_m + 1;
                else
                    nums1_l = nums1_m + 1;
            } else {
                if(nums1[nums1_m] > nums2[nums2_m])
                    nums1_r = nums1_m - 1;
                else
                    nums2_r = nums2_m - 1;
            }
        }
        return 0;
    }
};
