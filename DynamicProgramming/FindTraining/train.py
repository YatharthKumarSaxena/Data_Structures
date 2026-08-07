class Solution:
    def findWinner(self, n, x, y):
        dp = [False] * (n + 1)

        for i in range(1, n + 1):
            a = dp[i - 1] if i - 1 >= 0 else True
            b = dp[i - x] if i - x >= 0 else True
            c = dp[i - y] if i - y >= 0 else True

            dp[i] = not (a and b and c)

        return dp[n]