from typing import List

class Solution:
    def doDP(self, i, buy, fee, prices, dp):
        n = len(prices)
        if i==n: return 0
        elif dp[i][buy] != -1: return dp[i][buy]
        elif buy:
            dp[i][buy] = max(-prices[i]+self.doDP(i+1,0,fee,prices,dp),self.doDP(i+1,1,fee,prices,dp))
        else:
            dp[i][buy] = max(prices[i]-fee+self.doDP(i+1,1,fee,prices,dp),self.doDP(i+1,0,fee,prices,dp))
        return dp[i][buy]
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        dp = [[-1 for _ in range(2)] for _ in range(n)]
        return self.doDP(0,1,fee,prices,dp)