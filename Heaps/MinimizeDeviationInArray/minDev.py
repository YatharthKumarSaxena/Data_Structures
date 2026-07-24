from typing import List
import heapq

class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        pq = []
        n = len(nums)
        mn = float('inf')
        for i in range(n):
            if nums[i]%2: nums[i]*=2
            heapq.heappush(pq,-nums[i])
            mn = min(nums[i],mn)
        mx = -pq[0]
        ans = float('inf')
        while mx%2==0:
            mx //= 2
            heapq.heappop(pq)
            heapq.heappush(pq,-mx)
            mn = min(mx,mn)
            mx = -pq[0]
            ans = min(mx-mn,ans)
        return ans