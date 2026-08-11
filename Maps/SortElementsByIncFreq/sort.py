from typing import List
import heapq

class Solution:
    def frequencySort(self, arr: List[int]) -> List[int]:
        mp = dict()
        n = len(arr)
        pq = []
        for i in range(n):
            mp[arr[i]] = mp.get(arr[i],0)+1
        ans = []
        for ele,count in mp.items():
            heapq.heappush(pq,(count,-ele))
        while len(pq):
            count, ele = heapq.heappop(pq)
            ele = -ele
            while mp[ele]:
                mp[ele] -= 1
                ans.append(ele)
            del mp[ele]
        return ans