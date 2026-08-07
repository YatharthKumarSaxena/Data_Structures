from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        for i in range(m-1,0,-1):
            grid[i-1][n-1] += grid[i][n-1]
            
        for j in range(n-1,0,-1):
            grid[m-1][j-1] += grid[m-1][j]
                
        for i in range(m-1,0,-1):
            for j in range(n-1,0,-1):
                grid[i-1][j-1] += min(grid[i-1][j],grid[i][j-1])
            
        return grid[0][0]
