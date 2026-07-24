import heapq
from typing import List

class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        fractions = []
        n = len(arr)
        for i in range(n-1):
            for j in range(i+1,n):
                fractions.append((-arr[i]/arr[j],(arr[i],arr[j])))

        totalFractions = len(fractions)
        pq = []
        for i in range(totalFractions):
            heapq.heappush(pq,fractions[i])
            while len(pq)>k: heapq.heappop(pq)
        ans = [pq[0][1][0],pq[0][1][1]]
        return ans