void reverse(int* nums, int start, int end) {
    for(int i = start, j = end; i < (start+end)/2+1; i++, j--) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
void swap(int *nums, int a, int b) {
    int t = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}
void nextPermutation(int* nums, int numsSize) {
    int small = -1, large = -1;

    for(int i = numsSize - 1; i > 0; i--) {
        if(nums[i-1] < nums[i]) {
            small = i-1;
            break;
        }
    }

    if(small == -1) {
        reverse(nums, 0, numsSize - 1);
        return;
    }

    for(int i = numsSize - 1; i >= 0; i--) {
        if(nums[small] < nums[i]) {
            large = i;
            break;
        }
    }
    swap(nums, small, large);
    reverse(nums, small+1, numsSize-1);
}
