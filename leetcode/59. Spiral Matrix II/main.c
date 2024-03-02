/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int **ret = (int**)calloc (sizeof(int*), n);
    *returnColumnSizes = (int*) malloc(sizeof(int) * n);
    *returnSize = n;
    for(int i = 0; i < n; i++) {
        ret[i] = (int*) malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
        
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int count = 1;

    while(bottom >= top && right >= left) {
        for(int i = left; i <= right; i++)
            ret[top][i] = count ++;
        top ++;

        for(int i = top; i <= bottom; i++)
            ret[i][right] = count ++;
        right --;

        if(bottom >= top) {
            for(int i = right; i >= left; i--)
                ret[bottom][i] = count ++;
            bottom --;
        }

        if(right >= left) {
            for(int i = bottom; i >= top; i--)
                ret[i][left] = count ++;
            left ++;
        }
    }
    return ret;
}
