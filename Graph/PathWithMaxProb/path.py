from typing import List
import heapq

class Solution:
    def dijkstra(self, V, edges, succProb, src, dest):

        pq = []
        heapq.heappush(pq, (-1.0, src))   # Max Heap using negative probability

        prob = [0.0] * V
        prob[src] = 1.0

        adjList = [[] for _ in range(V)]

        for i in range(len(edges)):
            u = edges[i][0]
            v = edges[i][1]
            wt = succProb[i]

            adjList[u].append((v, wt))
            adjList[v].append((u, wt))

        while pq:

            probability, node = heapq.heappop(pq)
            probability = -probability

            if probability < prob[node]:
                continue

            for neighbour, wt in adjList[node]:

                newProbability = probability * wt

                if prob[neighbour] < newProbability:
                    prob[neighbour] = newProbability
                    heapq.heappush(pq, (-newProbability, neighbour))

        return prob[dest]

    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        return self.dijkstra(n, edges, succProb, start_node, end_node)