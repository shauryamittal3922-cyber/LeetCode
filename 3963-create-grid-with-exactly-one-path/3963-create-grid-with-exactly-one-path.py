class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        grid = ['.' * n]
        grid += [('#' * (n-1) + '.') for _ in range(m-1)]

        return grid