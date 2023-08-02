#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int numsSize){

    if (nums[0] < nums[numsSize-1]){
        return nums[0];
    }

    size_t begin = 0, end = numsSize, pivot;

    while(1) {

        pivot = begin + (end - begin)/2;

        if (nums[pivot] >= nums[0]){
            begin = pivot + 1;
        }
        else {
            end = pivot;
        }

        if(end == begin) return nums[begin];
    }

}

int main() {
    int numsSize = 5;
    int* nums = malloc(numsSize*sizeof(int));
    nums[0] = 5; // 4 3
    nums[1] = 1; // 5 4
    nums[2] = 2; // 1 5
    nums[3] = 3; // 2 1
    nums[4] = 4; // 3 2
    printf("%d\n", findMin(nums, numsSize));
    return 0;
}
