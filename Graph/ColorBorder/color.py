from typing import List

class Solution:
    def colorCompleteComponent(self, grid, row, col, origColor, newColor):
        n = len(grid)
        m = len(grid[0])
        if row<0 or col<0 or col>=m or row>=n: return
        elif grid[row][col] == newColor: return
        elif grid[row][col] == origColor:
            grid[row][col] = newColor
            self.colorCompleteComponent(grid,row-1,col,origColor, newColor)
            self.colorCompleteComponent(grid,row+1,col,origColor, newColor)
            self.colorCompleteComponent(grid,row,col-1,origColor, newColor)
            self.colorCompleteComponent(grid,row,col+1,origColor, newColor)

    def uncolorUnboundaryComponent(self, origGrid, grid, visited, row, col, origColor, newColor):
        n = len(grid)
        m = len(grid[0])
        if row<0 or col<0 or col>m-1 or row>n-1: return
        elif origGrid[row][col] != origColor: return
        elif grid[row][col] != newColor: return
        if visited[row][col]:
            return
        visited[row][col] = True
        if row > 0 and row < n-1 and col > 0 and col < m-1:
            if (origGrid[row-1][col] == origColor and
                origGrid[row+1][col] == origColor and
                origGrid[row][col-1] == origColor and
                origGrid[row][col+1] == origColor):
                grid[row][col] = origColor
        self.uncolorUnboundaryComponent(origGrid,grid,visited,row-1,col,origColor, newColor)
        self.uncolorUnboundaryComponent(origGrid,grid,visited,row+1,col,origColor, newColor)
        self.uncolorUnboundaryComponent(origGrid,grid,visited,row,col-1,origColor, newColor)
        self.uncolorUnboundaryComponent(origGrid,grid,visited,row,col+1,origColor, newColor)


    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:
        origColor = grid[row][col]
        origGrid = [row[:] for row in grid]
        self.colorCompleteComponent(grid,row,col,origColor,color)
        n = len(grid)
        m = len(grid[0])
        visited = [[False] * m for _ in range(n)]
        self.uncolorUnboundaryComponent(origGrid,grid,visited,row,col,origColor,color)
        return grid