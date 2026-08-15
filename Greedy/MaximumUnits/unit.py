import heapq

class Solution:
    def maximumUnits(self, boxTypes, truckSize):
        pq = []

        n = len(boxTypes)

        for i in range(n):
            units = boxTypes[i][1]
            boxes = boxTypes[i][0]

            heapq.heappush(pq, (-units, boxes))

        ans = 0

        while pq and truckSize > 0:
            units, boxes = heapq.heappop(pq)

            units = -units

            if truckSize - boxes < 0:
                boxes = truckSize
                truckSize = 0
            else:
                truckSize -= boxes

            ans += boxes * units

        return ans