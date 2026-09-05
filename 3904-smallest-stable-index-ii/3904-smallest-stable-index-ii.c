int firstStableIndex(int* nums, int numsSize, int k) {
    int* l_max = (int *)malloc(numsSize * sizeof(int));
    int* r_min = (int *)malloc(numsSize * sizeof(int));

    l_max[0] = nums[0];
    r_min[numsSize-1] = nums[numsSize-1];

    for(int i = 1; i < numsSize; i++){
        l_max[i] = (nums[i] > l_max[i-1])? nums[i] : l_max[i-1];
    }

    for(int i = numsSize-2; i >= 0; i--){
        r_min[i] = (nums[i] < r_min[i+1])? nums[i] : r_min[i+1];
    }

    for(int i = 0; i < numsSize; i++){
        if((l_max[i] - r_min[i]) <= k) return i;
    }
    return -1;
}