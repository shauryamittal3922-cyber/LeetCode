int reverseDegree(char* s) {
    int n = strlen(s);
    int res = 0;

    for(int i = 0; i < n; i++){
        int k = 26 - (s[i] - 'a');
        res += k*(i+1);
    }
    return res;
}