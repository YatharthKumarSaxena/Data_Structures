class Solution:
    def editDistance(self, s1, s2):
        n = len(s1)
        m = len(s2)

        dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

        # Base cases
        for j in range(m + 1):
            dp[n][j] = m - j

        for i in range(n + 1):
            dp[i][m] = n - i

        # Fill DP table
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if s1[i] == s2[j]:
                    dp[i][j] = dp[i + 1][j + 1]
                else:
                    dp[i][j] = 1 + min(
                        dp[i + 1][j + 1],  # Replace
                        dp[i][j + 1],      # Insert
                        dp[i + 1][j]       # Delete
                    )

        return dp[0][0]