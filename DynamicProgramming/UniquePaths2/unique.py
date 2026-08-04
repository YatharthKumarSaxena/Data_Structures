from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        # code here
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [[-1 for _ in range(n)] for _ in range(m)]

        obsFound = False
        for j in range(n):
            if obstacleGrid[0][j]: obsFound = True
            if not obsFound: dp[0][j] = 1
            else: dp[0][j] = 0

        obsFound = False
        for i in range(m):
            if obstacleGrid[i][0]: obsFound = True
            if not obsFound: dp[i][0] = 1
            else: dp[i][0] = 0

        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j]:
                    dp[i][j] = 0

        for i in range(m):
            for j in range(n):
                if i>0 and j>0 and not obstacleGrid[i][j]:
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1])
                    
        return dp[m-1][n-1]