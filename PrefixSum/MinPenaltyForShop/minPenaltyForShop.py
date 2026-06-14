class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        sufSum = [0]*(n+1)
        preSum = [0]*(n+1)
        idx = n-1
        while idx >= 0:
            sufSum[idx] += sufSum[idx+1]
            if customers[idx]=='Y':
                sufSum[idx] += 1
            idx -= 1
        idx = 1
        while idx <= n:
            preSum[idx] += preSum[idx-1]
            if customers[idx-1]=='N':
                preSum[idx] += 1
            idx += 1
        overallPenalty = [0] * (n+1)
        for i in range(n+1):
            overallPenalty[i] = preSum[i] + sufSum[i]
        minIdx = 0
        idx = 0
        minPenalty = overallPenalty[0]
        while idx <= n:
            if minPenalty > overallPenalty[idx]:
                minIdx = idx
                minPenalty = overallPenalty[idx]
            idx += 1
        return minIdx