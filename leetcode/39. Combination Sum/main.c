/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ret_size;
int **ret;

void dfs(int** ret, int target, int cur, int* can, int can_size, int* tmp, int tmp_len, int a, int *column) {
    if(target == cur) {
        column[ret_size] = tmp_len;
        for(int i = 0; i < tmp_len; i++)
            ret[ret_size][i] = tmp[i];
        ret_size ++;
        return;
    }
    if(target < cur) {
        return;
    }
    for(int i = a; i < can_size; i++) {
        if(cur+can[i] > target)
            continue;
        tmp[tmp_len] = can[i];
        dfs(ret, target, cur+can[i], can, can_size, tmp, tmp_len+1, i, column);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int tmp[100];
    ret = (int**)malloc(sizeof(int*) * 500);
    for(int i = 0; i < 500; i++)
        ret[i] = (int*)malloc(sizeof(int) * 100);
    *returnColumnSizes = (int*)malloc(sizeof(int*) * 500);
    ret_size = 0;

    dfs(ret, target, 0, candidates, candidatesSize, tmp, 0, 0, *returnColumnSizes);
    
    *returnSize = ret_size;
    return ret;
}
