class Solution:
    def doDP(self, coins, dp, amount):
        if amount==0: return 0
        elif dp[amount]!=-1: return dp[amount]
        dp[amount] = float('inf')
        n = len(coins)
        for i in range(n):
            if coins[i]<=amount:
                result = self.doDP(coins,dp,amount-coins[i])
                if result!=float('inf'):
                    dp[amount] = min(dp[amount],1+result)
        return dp[amount]
        
    def minCoins(self, coins: list[int], sum: int) -> int:
        # code here
        n = len(coins)
        dp = [-1 for _ in range(sum+1)]
        dp[0] = 0
        ans = self.doDP(coins,dp,sum)
        if ans == float('inf'):
            return -1
        return ans