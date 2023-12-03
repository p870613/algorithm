/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return (*(int*) a - *(int*)b);
}

int c(int **ret, int index, int *nums, int i, int j, int l, int r) {
    for (int k = 0; k < index; k++) {
        if(ret[k][0] == nums[i] && ret[k][1] == nums[j] &&
        ret[k][2] == nums[l] && ret[k][3] == nums[r])
            return false;                        
    }
    return true;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int **ret = (int**) malloc(sizeof(int*) * 5000);
    int index = 0;
    
    for (int i = 0; i < 5000; i++)
        ret[i] = (int*)malloc(sizeof(int) * 4);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 5000);
    
    
    //sort first
    qsort((void*) nums, numsSize, sizeof(int), cmp);

    for(int i = 0; i < numsSize - 3; i++) {
        for(int j = i+1; j < numsSize - 2; ++j) {
            if(j > i + 1 && nums[j] == nums[j-1])
                continue;
            
            long long new_target = (long long)target - nums[i] - nums[j];
            int l = j + 1, r = numsSize - 1;
            while(l < r) {
                // printf("%d %d %d %d\n", i, j, l, r);
                if (nums[l] + nums[r] == new_target) {
                    if(c(ret, index, nums, i, j, l, r)) {
                        ret[index][0] = nums[i];
                        ret[index][1] = nums[j];
                        ret[index][2] = nums[l];
                        ret[index][3] = nums[r];
                        (*returnColumnSizes)[index] = 4;
                        index ++;
                        
                    }  
                    l ++;
                    r --;
                } else if (nums[l] + nums[r] > new_target) {
                    r --;
                } else {
                    l ++;
                }   
            } 
        }
    }
    *returnSize = index;
    return ret;
}
