
struct data_t {
    int val;
    int min;
};
typedef struct {
    struct data_t data[10000];
    int index;
} MinStack;

MinStack *sort;
MinStack* minStackCreate() {
    MinStack *ar = (MinStack*) calloc(1, sizeof(MinStack));
    ar->data[0].min = INT_MIN;
    return ar;
}

void minStackPush(MinStack* obj, int val) {
     obj->data[obj->index].val = val;
    if(obj->index > 0) {
        if(obj->data[(obj->index)-1].min > val)
            obj->data[obj->index].min = val;
        else
            obj->data[(obj->index)].min = obj->data[(obj->index)-1].min; 
    } else {
        obj->data[obj->index].min = val;
    }
    obj->index ++; 
}

void minStackPop(MinStack* obj) {
    obj->index --;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->index-1].val;    
}

int minStackGetMin(MinStack* obj) {
    return obj->data[obj->index-1].min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
