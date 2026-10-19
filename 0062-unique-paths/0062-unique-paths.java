class Solution {
    private long calculate(int n, int r){
        if(r == 0 || r == n) return 1;

        if(r > n-r) r = n-r;

        long res = 1;
        for(int i = 1; i <= r; i++){
            res *= n;
            res /= i;
            n--;
        }
        return res;
    }

    public int uniquePaths(int m, int n) {
        return (int)calculate(m+n-2, m-1);
    }
}