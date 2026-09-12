/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct { long long l, r, w; int id; } Interval;
typedef struct { long long w; int ids[4]; int c; } DP;

int cmpI(const void* a, const void* b) {
    Interval *i1 = (Interval*)a, *i2 = (Interval*)b;
    if (i1->l != i2->l) return i1->l > i2->l ? 1 : -1;
    if (i1->r != i2->r) return i1->r > i2->r ? 1 : -1;
    return i1->id - i2->id;
}
int cmpInt(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int* maximumWeight(int** I, int n, int* col, int* ret) {
    Interval* A = malloc(n * sizeof(Interval));
    for (int i = 0; i < n; i++) A[i] = (Interval){I[i][0], I[i][1], I[i][2], i};
    qsort(A, n, sizeof(Interval), cmpI);

    DP dp[n + 1][5];
    for (int i = 0; i <= n; i++) for (int k = 0; k <= 4; k++) dp[i][k] = (DP){0, {0}, 0};

    for (int i = n - 1; i >= 0; i--) {
        int low = 0, high = n;
        while (low < high) { int m = (low + high) / 2; if (A[m].l > A[i].r) high = m; else low = m + 1; }

        for (int k = 1; k <= 4; k++) {
            DP best = dp[i + 1][k], take = dp[low][k - 1];
            take.w += A[i].w; take.ids[take.c++] = A[i].id;
            qsort(take.ids, take.c, sizeof(int), cmpInt);

            int better = take.w > best.w;
            if (take.w == best.w) {
                if (best.c == 0) better = 1;
                else {
                    for (int j = 0; j < take.c && j < best.c; j++) {
                        if (take.ids[j] < best.ids[j]) { better = 1; break; }
                        if (take.ids[j] > best.ids[j]) break;
                    }
                }
            }
            dp[i][k] = better ? take : best;
        }
    }
    *ret = dp[0][4].c;
    int* res = malloc(*ret * sizeof(int));
    for (int i = 0; i < *ret; i++) res[i] = dp[0][4].ids[i];
    free(A);
    return res;
}