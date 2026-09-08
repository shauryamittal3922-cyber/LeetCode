void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rev(int* nums, int s, int e){
    while(s < e){
        swap(&nums[s], &nums[e]);
        s++;
        e--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;

    while(i >= 0 && nums[i] >= nums[i+1]) i--;

    if(i >= 0){
        int j = numsSize - 1;
        while(nums[i] >= nums[j]) j--;

        swap(&nums[i], &nums[j]);
    }

    rev(nums, i+1, numsSize - 1);
}