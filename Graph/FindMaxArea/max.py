from collections import deque

class Solution:
    def findTotalNodeInConnComp(self, sr, sc, image, visited):
        m = len(image)
        n = len(image[0])

        qu = deque()
        qu.append((sr, sc))
        visited[sr][sc] = True

        dx = [-1, 0, 1, 0, 1, 1, -1, -1]
        dy = [0, -1, 0, 1, 1, -1, 1, -1]

        totalNodes = 1

        while qu:
            r, c = qu.popleft()

            for i in range(8):
                nr = r + dx[i]
                nc = c + dy[i]

                if 0 <= nr < m and 0 <= nc < n:
                    if not visited[nr][nc] and image[nr][nc]:
                        qu.append((nr, nc))
                        visited[nr][nc] = True
                        totalNodes += 1

        return totalNodes

    def findMaxArea(self, grid):
        m = len(grid)
        n = len(grid[0])

        visited = [[False] * n for _ in range(m)]

        maxNodes = 0

        for i in range(m):
            for j in range(n):
                if not visited[i][j] and grid[i][j]:
                    maxNodes = max(
                        maxNodes,
                        self.findTotalNodeInConnComp(i, j, grid, visited)
                    )

        return maxNodes