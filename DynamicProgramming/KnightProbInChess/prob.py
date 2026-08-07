class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:

        dp = [[[-1.0 for _ in range(k + 1)] for _ in range(n)] for _ in range(n)]

        directions = [
            (1, 2), (-1, 2),
            (2, 1), (2, -1),
            (1, -2), (-1, -2),
            (-2, 1), (-2, -1)
        ]

        def doDP(r, c, moves):
            if r < 0 or r >= n or c < 0 or c >= n:
                return 0.0

            if moves == 0:
                return 1.0

            if dp[r][c][moves] >= 0.0:
                return dp[r][c][moves]

            res = 0.0

            for dx, dy in directions:
                nr = r + dx
                nc = c + dy

                if 0 <= nr < n and 0 <= nc < n:
                    res += doDP(nr, nc, moves - 1) / 8.0

            dp[r][c][moves] = res
            return res

        return doDP(row, column, k)