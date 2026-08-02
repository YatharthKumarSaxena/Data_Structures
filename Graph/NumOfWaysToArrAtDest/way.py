from typing import List
import heapq

class Solution:
    MOD = 1000000007

    def dijkstra(self, V, edges, src, dest):

        pq = []
        heapq.heappush(pq, (0, src))

        dist = [float('inf')] * V
        ways = [0] * V

        dist[src] = 0
        ways[src] = 1

        adjList = [[] for _ in range(V)]

        for edge in edges:
            u = edge[0]
            v = edge[1]
            wt = edge[2]

            adjList[u].append((v, wt))
            adjList[v].append((u, wt))

        while pq:

            distance, node = heapq.heappop(pq)

            if distance > dist[node]:
                continue

            for neighbour, wt in adjList[node]:

                newDistance = distance + wt

                if newDistance < dist[neighbour]:

                    dist[neighbour] = newDistance
                    ways[neighbour] = ways[node]

                    heapq.heappush(pq, (newDistance, neighbour))

                elif newDistance == dist[neighbour]:

                    ways[neighbour] = (
                        ways[neighbour] + ways[node]
                    ) % self.MOD

        return ways[dest]

    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        return self.dijkstra(n, roads, 0, n - 1)