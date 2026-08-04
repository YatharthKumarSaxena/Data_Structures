class Solution:
    
    def doDP(self, n, dp):
        if n<=1: return n+1
        elif dp[n] != -1: return dp[n]
        dp[n] = self.doDP(n-1,dp) + self.doDP(n-2,dp)
        return dp[n]
        
    def countWays(self, n: int) -> int:
        # code here
        dp = [-1] * n
        return self.doDP(n-1,dp)