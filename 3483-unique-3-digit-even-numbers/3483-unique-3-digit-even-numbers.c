int totalNumbers(int* digits, int digitsSize) {
    int count[10] = {0};

    for(int i = 0; i < digitsSize; i++){
        count[digits[i]]++;
    }

    int nums = 0;

    for(int ones = 0; ones <= 8; ones += 2){
        if(count[ones] == 0) continue;
        count[ones]--;

        for(int hund = 1; hund <= 9; hund++){
            if(count[hund] == 0) continue;
            count[hund]--;

            for(int tens = 0; tens <= 9; tens++){
                if(count[tens] == 0) continue;
                nums++;
            }
            count[hund]++;
        }
        count[ones]++;
    }
    return nums;
}