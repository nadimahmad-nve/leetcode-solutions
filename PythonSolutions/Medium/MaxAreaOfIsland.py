class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        maxArea = 0 
        m = len(grid)
        n = len(grid[0])

        def dfs(i, j): 
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
                return 0 # Base case: Area is 0

            # Sink island
            grid[i][j] = 0

            area = 1 

            dx = [1, -1, 0, 0]
            dy = [0, 0, 1, -1]

            for k in range(4):
                new_x = i + dx[k]
                new_y = j + dy[k]
                area += dfs(new_x, new_y)
                
            return area
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1: 
                    maxArea = max(maxArea, dfs(i, j))
        
        return maxArea    