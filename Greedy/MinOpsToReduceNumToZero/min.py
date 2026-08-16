class Solution:
    def doDP(self, n: int, dp: list[int]) -> int:
        if bin(n).count("1") == 1:
            return 0

        if dp[n] != -1:
            return dp[n]

        if n % 2 == 0:
            dp[n] = self.doDP(n // 2, dp)
        else:
            dp[n] = 1 + min(
                self.doDP(n - 1, dp),
                self.doDP(n + 1, dp)
            )

        return dp[n]

    def minOperations(self, n: int) -> int:
        dp = [-1] * (n + 2)
        return self.doDP(n, dp) + 1