struct hash {
    int val;
    int count;
};

struct hash* hashmap_init(int len) {
    struct hash *ret = (struct hash*)malloc(sizeof(struct hash) * len);
    memset(ret, 0, sizeof(struct hash) * len);
    return ret;
}

int get_index(int len, int value) {
    return ((value % len) + len) % len;
}

int add_node(struct hash *hashmap, int value, int len) {
    int index = get_index(len, value);
    while(hashmap[index].val != value && hashmap[index].count != 0) {
        index = (index + 1) % len;
    }
    hashmap[index].val = value;
    hashmap[index].count ++;
    return hashmap[index].count;
}

bool containsDuplicate(int* nums, int numsSize) {
    struct hash *hashmap = hashmap_init(numsSize);
    for(int i = 0; i < numsSize; i++) {
        if(add_node(hashmap, nums[i], numsSize) > 1)
            return true;
    }
    return false;
}
