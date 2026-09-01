int compare(const void* a, const void* b){
    int x = *((int*)a);
    int y = *((int*)b);

    if(x < y) return -1;
    if(x > y) return 1;
    return 0;
}

int missingMultiple(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    int multi = k;
    int i = 0;

    while(1){
        while(i < numsSize && nums[i] < multi) i++;

        if(i == numsSize || nums[i] != multi) return multi;

        multi += k;
    }
}