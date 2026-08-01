from typing import List
from collections import deque

class Solution:
    def findMaxDisFromWaterSource(self,grid):
        # code here

        maxDis = -1

        m = len(grid)
        n = len(grid[0])

        qu = deque()
        
        visited = [[False for _ in range(n)] for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    qu.append(((i, j),0))
                    visited[i][j] = True


        dx = [-1, 0, 1, 0]
        dy = [0, -1, 0, 1]

        while qu:
            curr = qu.popleft()
            r = curr[0][0]
            c = curr[0][1]
            dis = curr[1]
            
            if grid[r][c] == 0:
                maxDis = max(maxDis, dis)

            for i in range(4):
                nr = r + dx[i]
                nc = c + dy[i]

                if 0 <= nr < m and 0 <= nc < n:
                    if not visited[nr][nc] and not grid[nr][nc]:
                        qu.append(((nr, nc),dis+1))
                        visited[nr][nc] = True

        return maxDis

    def maxDistance(self, grid: List[List[int]]) -> int:
        maxDis = -1
        m = len(grid)
        n = len(grid[0])

        return self.findMaxDisFromWaterSource(grid)