from typing import List
import heapq

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:

        rows = len(heights)
        cols = len(heights[0])

        effort = [[float('inf')] * cols for _ in range(rows)]
        effort[0][0] = 0

        pq = []
        heapq.heappush(pq, (0, 0, 0))   # (effort, row, col)

        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]

        while pq:

            currEffort, r, c = heapq.heappop(pq)

            if r == rows - 1 and c == cols - 1:
                return currEffort

            if currEffort > effort[r][c]:
                continue

            for k in range(4):

                nr = r + dr[k]
                nc = c + dc[k]

                if nr < 0 or nr >= rows or nc < 0 or nc >= cols:
                    continue

                edgeCost = abs(heights[r][c] - heights[nr][nc])

                newEffort = max(currEffort, edgeCost)

                if newEffort < effort[nr][nc]:
                    effort[nr][nc] = newEffort
                    heapq.heappush(pq, (newEffort, nr, nc))

        return 0