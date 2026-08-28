class Solution:

    def solve(self, mask, n, a, dp):

        if mask == (1 << n) - 1:
            return 1

        if dp[mask] != -1:
            return dp[mask]

        man = mask.bit_count()
        ans = 0

        for i in range(n):

            if a[man][i] and not (mask & (1 << i)):

                newMask = mask | (1 << i)

                ans += self.solve(newMask, n, a, dp)

        dp[mask] = ans
        return ans

    def countWays(self, a):

        n = len(a)

        dp = [-1] * (1 << n)

        return self.solve(0, n, a, dp)