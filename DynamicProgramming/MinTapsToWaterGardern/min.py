from typing import List

class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        INF = float('inf')
        dp = [INF] * (n+1)
        dp[0] = 0
        for i in range(n+1):
            start = max(0,i-ranges[i])
            end = min(n,i+ranges[i])
            for j in range(start,end+1):
                dp[end] = min(dp[j]+1,dp[end])
        return -1 if dp[end] == INF else dp[end]