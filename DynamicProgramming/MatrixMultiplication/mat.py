class Solution:
    def matrixMultiplication(self, arr):
        n = len(arr) - 1

        dp = [[-1] * (n + 1) for _ in range(n + 1)]

        def doDP(i, j):
            if i == j:
                return 0

            if dp[i][j] != -1:
                return dp[i][j]

            ans = float('inf')

            for k in range(i, j):
                ans = min(
                    ans,
                    doDP(i, k)
                    + doDP(k + 1, j)
                    + arr[i - 1] * arr[k] * arr[j]
                )

            dp[i][j] = ans
            return ans

        return doDP(1, n)