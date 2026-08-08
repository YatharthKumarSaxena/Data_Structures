class Solution:
    def countStrings(self, n, k):
        MOD = 1000000007

        dp = [[[-1 for _ in range(2)] for _ in range(k + 1)] 
              for _ in range(n + 1)]

        def doDP(n, k, lastChar):
            if n == 0:
                return 1 if k == 0 else 0

            if k < 0:
                return 0

            if dp[n][k][lastChar] != -1:
                return dp[n][k][lastChar]

            res = 0

            if lastChar:
                res = doDP(n - 1, k, 0) % MOD
                res = (res + doDP(n - 1, k - 1, 1)) % MOD
            else:
                res = doDP(n - 1, k, 0) % MOD
                res = (res + doDP(n - 1, k, 1)) % MOD

            dp[n][k][lastChar] = res
            return res

        return (doDP(n - 1, k, 0) +
                doDP(n - 1, k, 1)) % MOD