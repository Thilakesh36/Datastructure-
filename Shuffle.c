typedef struct {
    int *orig;
    int size;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution *res = calloc(sizeof(Solution), 1);
    res->orig = calloc(sizeof(int), numsSize);
    memcpy(res->orig, nums, sizeof(int) * numsSize);
    res->size = numsSize;
    return res;
}

int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj->size;
    return obj->orig;
}

void swap(int *a, int *b) {
    if(a != b) {
        int temp = *a;
        *a = *b; 
        *b = temp;
    }
}

int* solutionShuffle(Solution* obj, int* retSize) {
    int *res =   calloc(sizeof(int), obj->size);
    memcpy(res, obj->orig, sizeof(int) * obj->size);
    *retSize = obj->size;
    for(int i = 0; i < obj->size; i++) {
        int randIdx = rand() % obj->size;
        swap(&res[i], &res[randIdx]);
    }
    return res;
}

void solutionFree(Solution* obj) {
    free(obj->orig);
    free(obj);
}
