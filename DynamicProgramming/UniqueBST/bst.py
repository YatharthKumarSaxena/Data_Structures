class Solution:
    def numTrees(self, n: int) -> int:
        # code here
        if n<=1: return 1
        dp = [0] * (n+1)
        dp[0] = dp[1] = 1
        dp[2] = 2
        for i in range(3,n+1):
            for k in range(1,i+1):
                dp[i] += dp[k-1]*dp[i-k]
        return dp[n]