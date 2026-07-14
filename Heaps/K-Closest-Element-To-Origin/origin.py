import heapq

class Solution:
    def kClosest(self, points, k):
        # code here
        n = len(points)
        mp = {}
        for i in range(n):
            dis = points[i][0]**2 + points[i][1]**2
            mp[i] = dis
        pq = []
        for idx,dis in mp.items():
            heapq.heappush(pq,(-dis,idx))
            if len(pq)>k: heapq.heappop(pq)
        ans = []
        while len(pq):
            ans.append(points[pq[0][1]])
            heapq.heappop(pq)
        return ans
        