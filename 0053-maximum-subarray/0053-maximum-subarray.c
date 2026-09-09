int maxSubArray(int* nums, int numsSize) {
    int max = nums[0];
    int curr = nums[0];
    for(int i = 1; i < numsSize; i++){
        curr = (nums[i] > curr + nums[i]) ? nums[i] : curr + nums[i];
    
        if(max < curr) max = curr;
    }

    return max;
}