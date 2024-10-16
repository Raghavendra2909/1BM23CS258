int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int majorityElement(int* nums, int numsSize) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    int count = 1;
    int max_count = 1;
    int result = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > max_count) {
            max_count = count;
            result = nums[i];
        }
    }

    return result;
}
