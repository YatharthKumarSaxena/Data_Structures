from collections import deque

class Solution:
    def findMaxRowMaxColOfFarm(self, land, visited, r, c):
        m = len(land)
        n = len(land[0])

        qu = deque()
        qu.append((r, c))
        visited[r][c] = True

        maxR = r
        maxC = c

        dx = [-1, 0, 1, 0]
        dy = [0, -1, 0, 1]

        while qu:
            row, col = qu.popleft()

            maxR = max(maxR, row)
            maxC = max(maxC, col)

            for i in range(4):
                nr = row + dx[i]
                nc = col + dy[i]

                if 0 <= nr < m and 0 <= nc < n:
                    if not visited[nr][nc] and land[nr][nc] == 1:
                        visited[nr][nc] = True
                        qu.append((nr, nc))

        return (maxR, maxC)

    def findFarmland(self, land):
        m = len(land)
        n = len(land[0])

        visited = [[False] * n for _ in range(m)]
        ans = []

        for i in range(m):
            for j in range(n):
                if not visited[i][j] and land[i][j] == 1:
                    maxR, maxC = self.findMaxRowMaxColOfFarm(
                        land, visited, i, j
                    )

                    ans.append([i, j, maxR, maxC])

        return ans