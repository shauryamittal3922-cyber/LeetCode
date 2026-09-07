int distinctSubseqII(char* s) {
    int modulo = 1000000007;
    int n = strlen(s);
    int res = 0;

    int prev[26] = {0};
    for(int i = 0; i < n; i++){
        int idx = s[i] - 'a';

        long long curr = (((long long)res + 1 - prev[idx] + modulo) % modulo);

        prev[idx] = (res + 1) % modulo;
        res  = (res + curr) % modulo;
    }
    return res;
}