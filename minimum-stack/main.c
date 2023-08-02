#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* val;
    int* min;
    int* max;
    size_t cap, size;
} MinStack ;

MinStack* createMinStack() {
    MinStack * minStack = malloc(sizeof(MinStack));
    minStack->cap = 1; minStack->size = 0;
    minStack->val = malloc(sizeof (int));
    minStack->min = malloc(sizeof (int));
    minStack->max = malloc(sizeof (int));
    return minStack;
}

void pushMinStack(MinStack* minStack, int value){
    if(minStack->size == minStack->cap){
        minStack->cap *= 2;
        minStack->val = realloc(minStack->val, minStack->cap*sizeof(int));
        minStack->min = realloc(minStack->min, minStack->cap*sizeof(int));
        minStack->max = realloc(minStack->max, minStack->cap*sizeof (int));
    }

    minStack->val[minStack->size] = value;
    if(minStack->size == 0){
        minStack->min[0] = value;
        minStack->max[0] = value;
    }
    else{
        minStack->min[minStack->size] = min(minStack->min[minStack->size-1], value);
        minStack->max[minStack->size] = max(minStack->max[minStack->size-1], value);
    }


    minStack->size++;
}

void popMinStack(MinStack* minStack) {
    minStack->size--;
}

int getMinMinStack(MinStack* minStack){
    return minStack->min[minStack->size-1];
}

int getMaxMinStack(MinStack* minStack){
    return minStack->max[minStack->size-1];
}

int getTopMinStack(MinStack* minStack){
    return minStack->val[minStack->size-1];
}

void freeMinStack(MinStack* minStack) {
    if(minStack == NULL) return;
    if(minStack->val != NULL) free(minStack->val);
    if(minStack->min != NULL) free(minStack->min);
    if(minStack->max != NULL) free(minStack->max);
    free(minStack);
}

int main() {
    MinStack * minStack = createMinStack();

    pushMinStack(minStack, -2);
    printf("%d %d %d\n", getMaxMinStack(minStack), getTopMinStack(minStack), getMinMinStack(minStack));
    pushMinStack(minStack, 0);
    printf("%d %d %d\n", getMaxMinStack(minStack), getTopMinStack(minStack), getMinMinStack(minStack));
    pushMinStack(minStack, 3);
    printf("%d %d %d\n", getMaxMinStack(minStack), getTopMinStack(minStack), getMinMinStack(minStack));
    pushMinStack(minStack, -1);
    printf("%d %d %d\n", getMaxMinStack(minStack), getTopMinStack(minStack), getMinMinStack(minStack));
    pushMinStack(minStack, -4);
    printf("%d %d %d\n", getMaxMinStack(minStack), getTopMinStack(minStack), getMinMinStack(minStack));

    freeMinStack(minStack);
    return 0;
}