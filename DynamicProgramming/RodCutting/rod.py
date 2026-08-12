class Solution:
    def doDP(self, price, dp, i):
        if i==0: return 0
        elif dp[i] != -1: return dp[i]
        dp[i] = 0
        for k in range(1,i+1):
            dp[i] = max(dp[i],price[k-1]+self.doDP(price,dp,i-k))
        return dp[i]
    def cutRod(self, price: list[int]) -> int:
        # code here
        n = len(price)
        dp = [-1 for _ in range(n+1)]
        return self.doDP(price,dp,n)