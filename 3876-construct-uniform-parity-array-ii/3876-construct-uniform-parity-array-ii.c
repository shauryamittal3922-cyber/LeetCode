bool uniformArray(int* nums1, int nums1Size) {
    bool allEven = true;
    bool allOdd = true;

    int minEven = INT_MAX;
    int minOdd = INT_MAX;

    for(int i = 0; i < nums1Size; i++){
        if(nums1[i] % 2 == 0){
            allOdd = false;
            if(minEven > nums1[i]) minEven = nums1[i];
        }
        else{
            allEven = false;
            if(minOdd > nums1[i]) minOdd = nums1[i];
        }
    }
    return allOdd || allEven || minEven > minOdd;
}