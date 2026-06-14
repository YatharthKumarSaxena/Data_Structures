from typing import List

class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        n = len(satisfaction)
        satisfaction.sort()
        if satisfaction[n-1]<=0: return 0
        sufSum = [0]*n
        sufSum[n-1] = satisfaction[n-1]
        for i in range(n-2,-1,-1):
            sufSum[i] += (satisfaction[i] + sufSum[i+1])
        totalValue = 0
        prodVar = 1
        for i in range(n):
            if sufSum[i] >= 0:
                totalValue += prodVar*satisfaction[i]
                prodVar += 1
        return totalValue
