int numDistinct(char* s, char* t) {
    int a = strlen(s);
    int b = strlen(t);

    if(a < b) return 0;

    unsigned long long** table = (unsigned long long **)malloc((a+1) * sizeof(unsigned long long *));

    for(int i = 0; i <= a; i++){
        table[i] = (unsigned long long *)calloc(b+1, sizeof(unsigned long long));
    }

    for(int i = 0; i <= a; i++){
        table[i][0] = 1;
    }

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(s[i-1] == t[j-1]) table[i][j] = table[i-1][j] + table[i-1][j-1];
            else table[i][j] = table[i-1][j];
        }
    }

    int res = table[a][b];

    for(int i = 0; i<= a; i++) free(table[i]);

    free(table);
    return res;
}