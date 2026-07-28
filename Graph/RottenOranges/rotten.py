from collections import deque

class Solution:
    def orangesRot(self, grid):
        m = len(grid)
        if m == 0:
            return 0

        n = len(grid[0])
        qu = deque()

        # Add all initially rotten oranges
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    qu.append(((i, j), 0))

        maxTime = 0

        while qu:
            (row, col), time = qu.popleft()
            maxTime = time

            if row > 0 and grid[row - 1][col] == 1:
                grid[row - 1][col] = 2
                qu.append(((row - 1, col), maxTime + 1))

            if row < m - 1 and grid[row + 1][col] == 1:
                grid[row + 1][col] = 2
                qu.append(((row + 1, col), maxTime + 1))

            if col < n - 1 and grid[row][col + 1] == 1:
                grid[row][col + 1] = 2
                qu.append(((row, col + 1), maxTime + 1))

            if col > 0 and grid[row][col - 1] == 1:
                grid[row][col - 1] = 2
                qu.append(((row, col - 1), maxTime + 1))

        # Check if any fresh orange remains
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    return -1

        return maxTime