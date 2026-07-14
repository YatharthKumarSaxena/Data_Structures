import heapq
from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        pq = []
        n = len(stones)
        for i in range(n):
            heapq.heappush(pq,-stones[i])
        while len(pq)>1:
            firstStone = pq[0]
            heapq.heappop(pq)
            secondStone = pq[0]
            heapq.heappop(pq)
            diffStone = -abs(firstStone-secondStone)
            if diffStone:
                heapq.heappush(pq,diffStone)
            if len(pq)==0: return 0
        return -pq[0]