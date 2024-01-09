/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int l = 0, r = numsSize - 1;
    int *ret = (int*)malloc(sizeof(int) * 2);
    ret[0] = -1;
    ret[1] = -1;
    
    *returnSize = 2;
    if(numsSize == 0)
        return ret;
    while(l <= r) {
        int m = (l + r) / 2;
        if(nums[m] == target) {
            int ret_l = m;
            int ret_r = m;
            ret[0] = m;
            ret[1] = m;
            
            while(ret_l >= 0 && nums[ret_l] == target)
                ret[0] = ret_l --;
            while(ret_r < numsSize && nums[ret_r] == target)
                ret[1] = ret_r ++;
        }
        if(nums[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    return ret;
}
