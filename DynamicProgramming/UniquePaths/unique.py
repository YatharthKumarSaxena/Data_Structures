class Solution:
    def numberOfPaths(self, m, n):
        # code here
        dp = [[-1 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i==0 or j==0: dp[i][j] = 1
        for i in range(m):
            for j in range(n):
                if i>0 and j>0:
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1])
                    
        return dp[m-1][n-1]