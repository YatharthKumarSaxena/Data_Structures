class Solution:
    def cherryPickup(self, grid):
        n = len(grid)
        m = len(grid[0])

        dp = [[[-1 for _ in range(m)] for _ in range(m)] for _ in range(n)]

        def doDP(row, col1, col2):
            if col1 < 0 or col1 >= m or col2 < 0 or col2 >= m:
                return float('-inf')

            if row == n - 1:
                if col1 == col2:
                    return grid[row][col1]
                return grid[row][col1] + grid[row][col2]

            if dp[row][col1][col2] != -1:
                return dp[row][col1][col2]

            result = float('-inf')

            for d1 in range(-1, 2):
                for d2 in range(-1, 2):
                    result = max(
                        result,
                        doDP(row + 1, col1 + d1, col2 + d2)
                    )

            if result == float('-inf'):
                dp[row][col1][col2] = float('-inf')
                return dp[row][col1][col2]

            result += grid[row][col1]

            if col1 != col2:
                result += grid[row][col2]

            dp[row][col1][col2] = result
            return result

        return doDP(0, 0, m - 1)