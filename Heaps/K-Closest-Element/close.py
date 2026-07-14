import heapq
from typing import List

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        mp = {}
        n = len(arr)
        for i in range(n):
            dis = abs(x-arr[i])
            mp[i] = dis
        pq = []
        for idx,dis in mp.items():
            ele = arr[idx]
            Pair = (-dis,ele)
            if len(pq)==k:
                checkDis = -pq[0][0]
                checkEle = pq[0][1]
                if checkDis == dis:
                    if ele < checkEle:
                        heapq.heappop(pq)
                        heapq.heappush(pq,Pair)

                elif dis < checkDis:
                    heapq.heappop(pq)
                    heapq.heappush(pq,Pair)
            else: heapq.heappush(pq,Pair)
        ans = []
        while len(pq):
            ele = pq[0][1]
            ans.append(ele)
            heapq.heappop(pq)
        ans.sort()
        return ans
        