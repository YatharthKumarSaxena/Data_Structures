from typing import List

class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        k = minutes
        n = len(grumpy)
        maxSum = 0
        for i in range(k):
            maxSum += (customers[i]*grumpy[i])
        idx = 0
        prevSum = maxSum
        j = k
        while j<n:
            currSum = prevSum - (grumpy[j-k]*customers[j-k]) + (grumpy[j]*customers[j])
            if currSum > maxSum:
                maxSum = currSum
                idx = j-k+1
            prevSum = currSum
            j += 1
        totalCusSatisfied = 0
        for i in range(idx,idx+k):
            grumpy[i] = 0
        for i in range(n):
            if not grumpy[i]:
                totalCusSatisfied += customers[i]
        return totalCusSatisfied
