from typing import List
from collections import deque

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dist = [[float('inf') for _ in range(n)] for _ in range(m)]
        dist[0][0] = 0
        qu = deque()
        qu.append((0,0))
        directions = [
            (0, 1),    # 1 Right
            (0, -1),   # 2 Left
            (1, 0),    # 3 Down
            (-1, 0)    # 4 Up
        ]
        while len(qu):
            curr = qu.popleft()
            row = curr[0]
            col = curr[1]
            currDir = grid[row][col]
            for i in range(4):
                nx = row + directions[i][0]
                ny = col + directions[i][1]
                edgeWt = 1
                if i+1==currDir: edgeWt = 0
                if 0 <= nx < m and 0 <= ny < n:
                    if dist[nx][ny] > dist[row][col]+edgeWt:
                        dist[nx][ny] = dist[row][col]+edgeWt
                        if edgeWt == 0:
                            qu.appendleft((nx, ny))
                        else:
                            qu.append((nx, ny))
        return dist[m-1][n-1]
            
