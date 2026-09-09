long long countCommas(long long n) {
    if(n <= 999) return 0;

    long long comma = 0;
    long long k = 999;

    while(k <= n){
        comma += n - k;
        k = k*1000 + 999;
    }
    return comma;
}