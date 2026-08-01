from typing import List
import heapq

class Solution:
    def dijkstra(self, V: int, edges: List[List[int]], src: int) -> List[int]:

        pq = []
        heapq.heappush(pq, (0, src))

        dist = [float('inf')] * V
        dist[src] = 0

        adjList = [[] for _ in range(V)]

        for u, v, wt in edges:
            adjList[u].append((v, wt))
            adjList[v].append((u, wt))

        while pq:

            distance, node = heapq.heappop(pq)

            if distance > dist[node]:
                continue

            for neighbour, wt in adjList[node]:

                newDistance = distance + wt

                if dist[neighbour] > newDistance:
                    dist[neighbour] = newDistance
                    heapq.heappush(pq, (newDistance, neighbour))

        return dist