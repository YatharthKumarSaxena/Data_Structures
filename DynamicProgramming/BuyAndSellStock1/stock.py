class Solution:
    def maxProfit(self, prices):
        n = len(prices)

        prefMin = [float('inf')] * n
        prefMin[0] = prices[0]

        for i in range(1, n):
            prefMin[i] = min(prices[i], prefMin[i - 1])

        ans = 0

        for i in range(n):
            ans = max(ans, prices[i] - prefMin[i])

        return ans