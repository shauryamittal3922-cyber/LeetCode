int minSumOfLengths(int* arr, int arrSize, int target) {
    int* min_len = malloc(arrSize * sizeof(int));

    int left = 0;
    int sum = 0;
    int min = INT_MAX;
    int result = INT_MAX;

    for(int right = 0; right < arrSize; right++){
        sum += arr[right];

        while(sum > target) sum -= arr[left++];

        if(sum == target){
            int len = right - left + 1;

            if(left > 0 && min_len[left-1] != INT_MAX)
                result = result < len + min_len[left-1]? result : len + min_len[left-1];

            min = min < len? min : len;
        }

        min_len[right] = min;
    }
    free(min_len);
    return result == INT_MAX? -1 : result;
}