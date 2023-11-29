void merge(int* ar, int l, int m, int r) {
    int l_len = m - l + 1, r_len = r - m;
    int left[l_len], right[r_len];

    for(int i = 0; i < l_len; i++)
        left[i] = ar[l+i];
    for(int i = 0; i < r_len; i++)
        right[i] = ar[m+1+i];
   
    int l_index = 0, r_index = 0, ar_index = l;
    while(l_index < l_len && r_index < r_len) {
        if(left[l_index] < right[r_index])
            ar[ar_index ++] = left[l_index++];
        else
            ar[ar_index ++] = right[r_index++];
    }

    while(l_index < l_len)
        ar[ar_index ++] = left[l_index++];
    
    while(r_index < r_len)
        ar[ar_index++] = right[r_index ++];
}

void merge_sort(int* num, int l, int r) {
    if(r > l) {
        int m = (l + r) / 2;
        merge_sort(num, l, m);
        merge_sort(num, m+1, r);
        merge(num, l, m, r);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int index = 0;
    int **ret = (int**)malloc(sizeof(int*) * 20000);
   
    *returnColumnSizes = (int*)malloc(sizeof(int)*20000);
    for (int i = 0; i < 20000; i++){
        ret[i] = (int*)malloc(sizeof(int) * 3);
    }
    
    merge_sort(nums, 0, numsSize-1);

    for (int i = 0; i < numsSize-2; i++) {
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        int first = i, second = i + 1, third = numsSize - 1;
        int target = -nums[first];
        while(second < third) {
            if(target == (nums[second] + nums[third])) {
                ret[index][0] = nums[first];
                ret[index][1] = nums[second];
                ret[index][2] = nums[third];
                (*returnColumnSizes)[index] = 3;
                index++;
                while (second < third && nums[second] == nums[second+1])
                    second ++;
                while (second < third && nums[third] == nums[third-1])
                    third --;
                second ++;
                third --;
                
            } else if (target > (nums[second] + nums[third])){
                second ++;
            } else {
                third --;
            }
            
        }
    }
    *returnSize = index;
    return ret;
}
