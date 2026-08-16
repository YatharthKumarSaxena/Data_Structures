import heapq

class Solution:
    def minSum(self, arr1: list[int], arr2: list[int]) -> int:
        pq1 = []
        pq2 = []

        for i in range(len(arr1)):
            heapq.heappush(pq1, (arr1[i], i))

        for i in range(len(arr2)):
            heapq.heappush(pq2, (arr2[i], i))

        while pq1 and pq2:
            pair1 = heapq.heappop(pq1)
            pair2 = heapq.heappop(pq2)

            idx1 = pair1[1]
            idx2 = pair2[1]

            ele1 = pair1[0]
            ele2 = pair2[0]

            # Different indices
            if idx1 != idx2:
                return ele1 + ele2

            # Same index
            if not pq1:
                heapq.heappush(pq2, pair2)
                continue

            if not pq2:
                heapq.heappush(pq1, pair1)
                continue

            next1 = pq1[0]
            next2 = pq2[0]

            option1 = next1[0] + pair2[0]
            option2 = pair1[0] + next2[0]

            if option1 < option2:
                # arr1 ka next pair lena better hai
                heapq.heappush(pq2, pair2)
            else:
                # arr2 ka next pair lena better hai
                heapq.heappush(pq1, pair1)

        return 0