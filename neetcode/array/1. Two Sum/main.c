/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct element {
    int value;
};

struct hashmap {
    int size;
    struct element **table;
};

struct hashmap* init_hashmap(int size) {
    struct hashmap* map = (struct hashmap*) calloc(1, sizeof(struct hashmap));
    map->size = size;
    map->table = (struct element**) calloc(size, sizeof(struct element*));
    return map;
}

void free_hashmap(struct hashmap* map) {
    struct element **cur = map->table;
    for(int i = 0; i < map->size; i++)
        free(cur[i]);
    free(cur);
    free(map);    
}

int hash(struct hashmap *map, int val) {
    return ((val % map->size) + map->size) % map->size;
}

struct element* get_element(struct hashmap *map, int val) {
    int key = hash(map, val);
    return map->table[key];
}

void insert_element(struct hashmap *map, int val, int index) {
    int key = hash(map, val);
    struct element *new_node = (struct element*) malloc(sizeof(struct element));
    new_node->value = index;
    map->table[key] = new_node;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashmap *map = init_hashmap(numsSize * 10);
    int *ret = (int*) malloc(sizeof(int) * 2);

    for(int i = 0; i < numsSize; i++) {
        struct element *e = get_element(map, target-nums[i]);
        if(e != NULL && e->value != i) {
            ret[0] = i;
            ret[1] = e->value; 
            *returnSize = 2;
            free_hashmap(map);
            return ret;
        }
        insert_element(map, nums[i], i);
    }  
    *returnSize = 0;
    return NULL;
}
