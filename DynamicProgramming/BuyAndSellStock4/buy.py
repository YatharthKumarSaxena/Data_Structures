class Solution:
    def maxProfit(self, k, prices):
        n = len(prices)

        dp = [[[-1 for _ in range(2)] for _ in range(k + 1)] for _ in range(n + 1)]

        def doDP(i, k, transaction):
            if i == n or k == 0:
                return 0

            if dp[i][k][transaction] != -1:
                return dp[i][k][transaction]

            if transaction:
                res = max(
                    prices[i] + doDP(i + 1, k - 1, 0),   # Sell
                    doDP(i + 1, k, 1)                    # Skip
                )
            else:
                res = max(
                    -prices[i] + doDP(i + 1, k, 1),     # Buy
                    doDP(i + 1, k, 0)                   # Skip
                )

            dp[i][k][transaction] = res
            return res

        return doDP(0, k, 0)