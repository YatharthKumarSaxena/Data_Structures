class Solution:
    def noOfWays(self, m,n,x):
        # code here
        dp = [[0 for _ in range(x+1)] for _ in range(n+1)]
        dp[0][0] = 1
        for dice in range(1,n+1):
            for Sum in range(0,x+1):
                dp[dice][Sum] = 0
                for face in range(1,m+1):
                    if Sum-face>=0:
                        dp[dice][Sum] = dp[dice][Sum]+dp[dice-1][Sum-face]
                        
        return dp[n][x]