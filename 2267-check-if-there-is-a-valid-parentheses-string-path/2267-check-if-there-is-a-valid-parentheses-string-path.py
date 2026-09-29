class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m = len(grid)
        n = len(grid[0])

        if (m+n-1) % 2 != 0:
            return False
        
        visited = {}

        def dfs(r, c, count) -> bool:
            count += 1 if grid[r][c] == '(' else -1

            if count < 0:
                return False
            
            if r == m-1 and c == n-1:
                return count == 0
            
            curr = (r, c, count)
            if curr in visited:
                return visited[curr]
            
            valid = (r+1 < m and dfs(r+1, c, count)) or (c+1 < n and dfs(r, c+1, count))

            visited[curr] = valid
            return valid


        return dfs(0, 0, 0)