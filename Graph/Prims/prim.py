from typing import List
import heapq

class Solution:
    def spanningTree(self, V: int, edges: List[List[int]]) -> int:

        pq = []
        heapq.heappush(pq, (0, 0))

        visited = [False] * V
        minCost = 0

        adjList = [[] for _ in range(V)]

        for u, v, wt in edges:
            adjList[u].append((v, wt))
            adjList[v].append((u, wt))

        while pq:

            currDist, node = heapq.heappop(pq)

            if visited[node]:
                continue

            visited[node] = True
            minCost += currDist

            for neighbour, wt in adjList[node]:
                if not visited[neighbour]:
                    heapq.heappush(pq, (wt, neighbour))

        return minCost