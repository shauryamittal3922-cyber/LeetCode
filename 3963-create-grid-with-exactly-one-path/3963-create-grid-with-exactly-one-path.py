class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        grid = [['#'] * n for _ in range(m)]

        for i in range(n):
            grid[0][i] = '.'

        for i in range(m):
            grid[i][n - 1] = '.'

        return ["".join(row) for row in grid]