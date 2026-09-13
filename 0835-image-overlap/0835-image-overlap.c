int largestOverlap(int** img1, int img1Size, int* img1ColSize, int** img2, int img2Size, int* img2ColSize) {
    int n = img1Size;

    int* ones1_r = malloc(n*n * sizeof(int));
    int* ones1_c = malloc(n*n * sizeof(int));
    int* ones2_r = malloc(n*n * sizeof(int));
    int* ones2_c = malloc(n*n * sizeof(int));

    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(img1[i][j] == 1){
                ones1_r[c1] = i;
                ones1_c[c1++] = j;
            }

            if(img2[i][j] == 1){
                ones2_r[c2] = i;
                ones2_c[c2++] = j;
            }
        }
    }

    if(c1 == 0 || c2 == 0){
        free(ones1_r);
        free(ones1_c);
        free(ones2_r);
        free(ones2_c);
        return 0;
    }

    int size = 2*n - 1;
    int* freq = calloc(size*size, sizeof(int));
    int overlap = 0;

    for(int i = 0; i < c1; i++){
        for(int j = 0; j < c2; j++){
            int row_shift = ones2_r[j] - ones1_r[i] + n-1;
            int col_shift = ones2_c[j] - ones1_c[i] + n-1;

            int idx = row_shift * size + col_shift;
            freq[idx]++;

            if(freq[idx] > overlap) overlap = freq[idx];
        }
    }
    free(ones1_r);
    free(ones1_c);
    free(ones2_r);
    free(ones2_c);
    free(freq);
    return overlap;
}