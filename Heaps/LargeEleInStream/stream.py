from typing import List
import heapq

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.pq = []
        self.k = k
        n = len(nums)
        for i in range(n):
            heapq.heappush(self.pq,nums[i])
            if len(self.pq) > self.k:
                heapq.heappop(self.pq)  

    def add(self, val: int) -> int:
        heapq.heappush(self.pq,val)
        if len(self.pq) > self.k:
            heapq.heappop(self.pq)
        if len(self.pq)<self.k: return -1
        return self.pq[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)


class Solution:
    def kthLargest(self, arr, k):
        # code here 
        
        kLarge = KthLargest(k,[])
        n = len(arr)
        ans = []
        
        for i in range(n):
            ans.append(kLarge.add(arr[i]))
        
        return ans