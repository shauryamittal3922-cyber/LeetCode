/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** maxNumOfSubstrings(char* s, int* returnSize) {
    int n = strlen(s);
    int l[26];
    int r[26];

    for(int i = 0; i < 26; i++){
        l[i] = n;
        r[i] = -1;
    }

    for(int i = 0; i < n; i++){
        if(l[s[i] - 'a'] == n) l[s[i] - 'a'] = i;
        r[s[i] - 'a'] = i;
    }

    int resL[26];
    int resR[26];
    int count = 0;  //number of valid sub strings so far
    int end = -1;   //last index of previous valid sub string

    for(int i = 0; i < n; i++){
        int idx = s[i] - 'a';
        if(i != l[idx]) continue;

        int valid = 1;  // to check valid sub string
        int right = r[idx];
        for(int j = i; j < right; j++){
            int k = s[j] - 'a';
            if(l[k] < i){
                valid = 0;
                break;
            }
            if(r[k] > right) right = r[k];
        }

        if(valid){
            if(i > end){
                resL[count] = i;
                resR[count++] = right;
                end = right;
            }
            else if(right < resR[count - 1]){
                resL[count - 1] = i;
                resR[count - 1] = right;
                end = right;
            }
        }
    }

    char** res = malloc(count * sizeof(char *));
    for(int i = 0; i < count; i++){
        int len = resR[i] - resL[i] + 1;
        res[i] = malloc((len+1) * sizeof(char));
        memcpy(res[i], s + resL[i], len);
        res[i][len] = '\0';
    }

    * returnSize = count;
    return res;
}