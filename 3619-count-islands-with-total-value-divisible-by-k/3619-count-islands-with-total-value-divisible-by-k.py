class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        island_count = 0
        
        for r in range(m):
            for c in range(n):
                if grid[r][c] <= 0:
                    continue
                
                island_sum = 0
                stack = [(r, c)]
                
                while stack:
                    curr_r, curr_c = stack.pop()
                    if grid[curr_r][curr_c] <= 0:
                        continue
                        
                    island_sum += grid[curr_r][curr_c]
                    grid[curr_r][curr_c] = 0
                    
                    for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                        nr, nc = curr_r + dr, curr_c + dc
                        if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] > 0:
                            stack.append((nr, nc))
                            
                if island_sum % k == 0:
                    island_count += 1
                    
        return island_count