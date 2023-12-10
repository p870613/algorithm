int searchInsert(int* nums, int numsSize, int target) {
  int l = 0, r = numsSize - 1;
  int ret = 0;

  while(l < r) {
    int m = (l + r) / 2;
    if(nums[m] == target) {
      return m;
      break;
    } else if(nums[m] > target) {
      r = m;
    } else {
      l = m + 1;
    }
  }
    if(target > nums[r])
        return r + 1;
    return r;
}
