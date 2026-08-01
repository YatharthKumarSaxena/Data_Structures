from collections import deque

class Solution:
    def checkSubIsland(self, grid1, grid2, visited, r, c):
        m = len(grid1)
        n = len(grid1[0])

        qu = deque()
        qu.append((r, c))
        visited[r][c] = True

        dx = [-1, 0, 1, 0]
        dy = [0, -1, 0, 1]

        isSubIsland = True

        while qu:
            row, col = qu.popleft()

            if grid1[row][col] == 0:
                isSubIsland = False

            for i in range(4):
                nr = row + dx[i]
                nc = col + dy[i]

                if 0 <= nr < m and 0 <= nc < n:
                    if not visited[nr][nc] and grid2[nr][nc] == 1:
                        visited[nr][nc] = True
                        qu.append((nr, nc))

        return isSubIsland

    def countSubIslands(self, grid1, grid2):
        m = len(grid1)
        n = len(grid1[0])

        visited = [[False] * n for _ in range(m)]

        ans = 0

        for i in range(m):
            for j in range(n):
                if not visited[i][j] and grid2[i][j] == 1:
                    if self.checkSubIsland(grid1, grid2, visited, i, j):
                        ans += 1

        return ans