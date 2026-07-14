import heapq
from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = {}
        n = len(nums)
        for i in range(n):
            mp[nums[i]] = mp.get(nums[i],0) + 1
        heap = []
        for key,value in mp.items():
            heap.append((value,key))
            heapq.heapify(heap)
            if len(heap) > k: heapq.heappop(heap)
        ans = []
        while len(heap):
            ans.append(heap[-1][1])
            heap.pop()
        return ans