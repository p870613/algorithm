/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int *ret = (int*) malloc(matrixSize * (* matrixColSize) * sizeof(int));
    int index = 0;
    int raw_len = matrixSize, col_len = *matrixColSize;
    int top = 0, bottom = raw_len - 1;
    int left = 0, right = col_len - 1;

    while(top <= bottom && right >= left) {
        for(int i = left; i <= right; i++)
            ret[index++] = matrix[top][i];
        top ++;

        for(int i = top; i <= bottom; i++)
            ret[index++] = matrix[i][right];     
        right --;

        if(bottom >= top) {
            for(int i = right; i >= left; i--)
                ret[index++] = matrix[bottom][i];
            bottom --;
        }
        if(right >= left) {
            for(int i = bottom; i >= top; i--) {
                ret[index++] = matrix[i][left];
            }
            left ++;
        }  
    }   
    *returnSize = index;
    return ret;
}
