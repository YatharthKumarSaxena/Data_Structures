from collections import deque
from typing import List

class Solution:
    def detectCycleByBFS(self, grid, visited, r, c, parent):
        m = len(grid)
        n = len(grid[0])
        color = grid[r][c]
        qu = deque()
        qu.append((r,c))
        visited[r][c] = True
        directions = [
            (-1, 0),  # Up
            (1, 0),   # Down
            (0, -1),  # Left
            (0, 1)    # Right
        ]
        while len(qu):
            (row,col) = qu.popleft()
            for dx,dy in directions:
                newX = row + dx
                newY = col + dy
                if newX >= 0 and newX < m and newY >= 0 and newY < n and color == grid[newX][newY]:
                    if visited[newX][newY] and parent[row][col] != (newX,newY): return True
                    elif not visited[newX][newY]:
                        qu.append((newX,newY))
                        visited[newX][newY] = True
                        parent[newX][newY] = (row,col)
        return False
            
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m = len(grid)
        n = len(grid[0])
        visited = [[False for _ in range(n)] for _ in range(m)]
        parent = [[(-1,-1) for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if not visited[i][j]:
                    if self.detectCycleByBFS(grid,visited,i,j,parent): return True
        return False