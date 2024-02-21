/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void permute(int* nums, int numsSize, int* returnSize, int **ret, int *visit, int count, int *tmp) {
    if(count == numsSize) {
        for(int i = 0; i < numsSize; i++)
            ret[*returnSize][i] = tmp[i];
        (*returnSize) ++;
        return;
    }

    for(int i = 0; i < numsSize; i++) {
        if(visit[i] == 1)
            continue;
        if(i != 0 && visit[i-1] == 1 && nums[i] == nums[i-1])
            continue;

        tmp[count] = nums[i];
        visit[i] = 1;
        permute(nums, numsSize, returnSize, ret, visit, count+1, tmp);
        visit[i] = 0;
    }
    
}
int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int visit[numsSize], tmp[numsSize];
    *returnSize = 0;
    *returnColumnSizes = (int*) malloc(sizeof(int) * 800);
    int **ret = (int **)malloc(sizeof(int*) * 800);

    for(int i = 0; i < 800; i++)
        ret[i] = (int*)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++)
        visit[i] = 0;
    
    permute(nums, numsSize, returnSize, ret, visit, 0, tmp);
    for(int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = numsSize;
    return ret;
}
