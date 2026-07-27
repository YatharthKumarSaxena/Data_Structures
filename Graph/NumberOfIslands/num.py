class Solution:
    def doDFS(self, grid, visited, r, c):
        n = len(grid)
        m = len(grid[0])

        if r < 0 or c < 0 or r >= n or c >= m:
            return

        if visited[r][c] or grid[r][c] == 0:
            return

        visited[r][c] = True

        # 8 directions
        self.doDFS(grid, visited, r - 1, c)
        self.doDFS(grid, visited, r, c - 1)
        self.doDFS(grid, visited, r + 1, c)
        self.doDFS(grid, visited, r, c + 1)
        self.doDFS(grid, visited, r - 1, c - 1)
        self.doDFS(grid, visited, r + 1, c + 1)
        self.doDFS(grid, visited, r - 1, c + 1)
        self.doDFS(grid, visited, r + 1, c - 1)

    def countIslands(self, grid):
        n = len(grid)
        if n == 0:
            return 0

        m = len(grid[0])

        adjGraph = [[0] * m for _ in range(n)]
        visited = [[False] * m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 'L':
                    adjGraph[i][j] = 1

        cc = 0

        for i in range(n):
            for j in range(m):
                if not visited[i][j] and adjGraph[i][j]:
                    self.doDFS(adjGraph, visited, i, j)
                    cc += 1

        return cc