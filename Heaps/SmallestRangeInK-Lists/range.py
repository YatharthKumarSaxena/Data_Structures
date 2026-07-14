import heapq

class Solution:
    def findSmallestRange(self, nums):
        # code here
        n = len(nums)
        pq = []
        mx = -float('inf')
        for i in range(n):
            mx = max(mx,nums[i][0])
            heapq.heappush(pq,(nums[i][0],(i,0)))
        mn = pq[0][0]
        start = mn
        end = mx
        while True:
            row = pq[0][1][0]
            col = pq[0][1][1]
            heapq.heappop(pq)
            if col == len(nums[row])-1: break
            heapq.heappush(pq,(nums[row][col+1],(row,col+1)))
            mx = max(mx,nums[row][col+1])
            mn = pq[0][0]
            if mx-mn < end-start:
                start = mn
                end = mx
        return (start,end)