from typing import List
from collections import deque

class Solution:
    def doDFSInComp(self, grid, r, c, color, newColor):
        n = len(grid)
        if r<0 or c<0 or c>=n or r>=n: return
        elif grid[r][c] == newColor: return
        elif grid[r][c] != color: return
        else:
            grid[r][c] = newColor
            self.doDFSInComp(grid,r-1,c,color,newColor)
            self.doDFSInComp(grid,r,c-1,color,newColor)
            self.doDFSInComp(grid,r+1,c,color,newColor)
            self.doDFSInComp(grid,r,c+1,color,newColor)

    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)

        isFound = False
        for i in range(n):
            for j in range(n):
                if grid[i][j]: 
                    self.doDFSInComp(grid,i,j,grid[i][j],-1)
                    isFound = True
                    break
            if isFound: break

        qu = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == -1: 
                    qu.append(((i,j),0))

        while len(qu):
            ((r,c),level) = qu.popleft()
            if r>0: 
                if grid[r-1][c]==1: return level
                elif grid[r-1][c]==0:
                    grid[r-1][c] = -1
                    qu.append(((r-1,c),level+1))
            if c>0:
                if grid[r][c-1]==1: return level
                elif grid[r][c-1]==0:
                    grid[r][c-1] = -1
                    qu.append(((r,c-1),level+1))
            if r<n-1:  
                if grid[r+1][c]==1: return level
                elif grid[r+1][c]==0:
                    grid[r+1][c] = -1
                    qu.append(((r+1,c),level+1))
            if c<n-1: 
                if grid[r][c+1]==1: return level
                elif grid[r][c+1]==0:
                    grid[r][c+1] = -1
                    qu.append(((r,c+1),level+1))

        return 0