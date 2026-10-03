from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        islands = 0 

        def dfs(i, j, grid, m, n):
            if (i < 0 or i >= m or j < 0 or j >= n):
                return 
            
            if grid[i][j] == "0":
                return 

            # Sink
            grid[i][j] = "0"

            dx = [1,-1, 0, 0]
            dy = [0, 0, 1, -1]

            for k in range(4):
                new_x = i + dx[k]
                new_y = j + dy[k]

                dfs(new_x, new_y, grid, m, n)

        m = len(grid) 
        n = len(grid[0])

        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    islands += 1 
                    dfs(i, j, grid, m, n)
        
        return islands 