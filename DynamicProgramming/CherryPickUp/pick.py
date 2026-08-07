class Solution:
    def cherryPickup(self, grid):
        n = len(grid)

        dp = [[[-1 for _ in range(55)] for _ in range(55)] for _ in range(55)]

        def doDP(i, j, x, y):
            if (
                i >= n or j >= n or
                x >= n or y >= n or
                grid[i][j] == -1 or
                grid[x][y] == -1
            ):
                return float('-inf')

            if i == n - 1 and j == n - 1:
                return grid[i][j]

            if dp[i][j][x] != -1:
                return dp[i][j][x]

            result = float('-inf')

            result = max(result, doDP(i, j + 1, x + 1, y))
            result = max(result, doDP(i + 1, j, x + 1, y))
            result = max(result, doDP(i, j + 1, x, y + 1))
            result = max(result, doDP(i + 1, j, x, y + 1))

            if result == float('-inf'):
                dp[i][j][x] = float('-inf')
                return dp[i][j][x]

            result += grid[i][j]
            result += grid[x][y]

            if i == x and j == y and grid[i][j]:
                result -= 1

            dp[i][j][x] = result
            return dp[i][j][x]

        ans = doDP(0, 0, 0, 0)

        if ans == float('-inf'):
            return 0

        return ans