/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct data {
    uint64_t hash;
    char *str;
    struct data *next;
};

struct data *mem;

static int primes[] = {48008689,8201621,90600877,75459919,20814037,19444259,72898607,30409369,13462721,28115371,30260063,68754823,18208543,3147953,63494831,9804499,35035243,37437263,58757497,16340869,42516437,42172321,61028663,80666801,70206893,66390833};

int hashval(char* str) {
    uint64_t ret = 0;

    for(int i = 0; i < strlen(str); i++)
        ret = ret + primes[str[i] - 'a'];

    return ret;
}

struct data* newnode(char* str, uint64_t hash, struct data* next) {
    struct data* ret = mem;
    mem->hash = hash;
    mem->next = next;
    mem->str = str;
    mem=&mem[1];

    return ret;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    int index;
    uint64_t hash;
    int map_size = strsSize * 2 + 1;
    struct data** map = (struct data**) calloc(map_size, sizeof(struct data*));
    int *amount = (int*) calloc(map_size, sizeof(int));
    *returnSize = 0;
    mem = (struct data*) malloc(sizeof(struct data) * map_size);

    for(int i = 0; i < strsSize; i++) {
        hash = hashval(strs[i]);
        index = hash % map_size;

        while(map[index] != NULL && map[index]->hash != hash)
            index = (index + 1) % map_size;
        
        if(map[index] == NULL)
            (*returnSize) ++;
        
        map[index] = newnode(strs[i], hash, map[index]);
        amount[index] ++;
    }
   
    char ***ret = (char***) malloc(sizeof(char**) * (*returnSize));
    *returnColumnSizes = (int*) calloc(sizeof(int), (*returnSize));
    index = 0;

    for(int i = 0; i < map_size; i++) {
        if(map[i] != NULL) {
            ret[index] = (char**) malloc(sizeof(char*) * amount[i]);
            (*returnColumnSizes)[index] = amount[i];
           
            struct data *cur = map[i];
            for(int j = 0; j < amount[i]; j++) {
                ret[index][j] = cur->str;
                cur=cur->next;
            }
            index ++;
        }
    }
    return ret;
}
