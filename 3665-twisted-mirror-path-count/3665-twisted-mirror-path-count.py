class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        mod = 10**9 + 7
        m, n = len(grid), len(grid[0])

        dp = [[0, 0] for _ in range(n)]
        dp[0] = [1, 1]

        for i in range(m):
            for j in range(n):

                if i == 0and j == 0:
                    continue
                
                left = dp[j-1][0] if j > 0 else 0
                top = dp[j][1] if i > 0 else 0

                if grid[i][j] == 0:
                    total = (left + top) % mod
                    dp[j] = [total, total]
                else:
                    dp[j] = [top, left]
                
        return dp[n-1][0]