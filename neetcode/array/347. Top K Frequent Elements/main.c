/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct data{
    int count;
    int val;
};

int cmp(const void* a, const void* b) {
    return ((struct data*)b)->count - ((struct data*)a)->count; 
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int *ret = (int*) malloc(sizeof(int) * k);
    *returnSize = k;
    int count[20001];
    int true_size = 0;
    struct data d[numsSize];
    int index = 0;

    memset(count, 0, sizeof(count));

    for(int i = 0; i < numsSize; i++)
        count[nums[i] + 10000] ++;
    for(int i = 0; i < 20001; i++) {
        if(count[i]) {
            d[index].val = i - 10000;
            d[index].count = count[i];
            index ++; 
        }
    }

    qsort(d, index, sizeof(struct data), cmp);
    for(int i = 0; i < k; i++) {
        ret[i] = d[i].val;
    }
    return ret;
}
