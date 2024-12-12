#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, complement;
    for (i = 0; i < numsSize; ++i) {
        complement = target - nums[i];
        for (j = 0; j < numsSize; ++j) {
            if (nums[j] == complement && (i != j)) {
                *returnSize = 2;
                int *returnArr = (int *) malloc(*returnSize * sizeof(int));
                returnArr[0] = i;
                returnArr[1] = j;
                return returnArr;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    int *result = twoSum(nums, numsSize, target, &returnSize);
    
    if (result != NULL) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result); // 釋放 malloc 的記憶體
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}
