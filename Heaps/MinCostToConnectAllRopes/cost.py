import heapq

class Solution:
   def minCost(self, arr):
    # code here
        pq = []
        n = len(arr)
        for i in range(n):
            heapq.heappush(pq,arr[i])
        ans = 0
        while len(pq)>1:
            f = pq[0]
            heapq.heappop(pq)
            if len(pq):
                s = pq[0]
                heapq.heappop(pq)
                heapq.heappush(pq,f+s)
                ans += (f+s);
        return ans