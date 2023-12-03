int cmp(const void *a, const void *b) {
    return (*(int*) a - *(int*)b);
}
int threeSumClosest(int* nums, int numsSize, int target) {
    qsort((void*) nums, numsSize, sizeof(int), cmp);

    int close = 30000, ret = 0;

    for(int i = 0; i < numsSize - 2; i++) {
        int l = i + 1, r = numsSize - 1;
        while(r > l) {
            int t = nums[i] + nums[l] + nums[r];
            int divide = target - t;
            if(divide < 0)
                divide = -divide;
            if(divide < close) {
                close = divide;
                ret = t;
                printf("%d\n", ret);
            }
         
            if (target > t) 
                l ++;
            else if (t > target)
                r --;
            else {
                ret = target;
                break;
            }
        } 
    }
    return ret;
}
