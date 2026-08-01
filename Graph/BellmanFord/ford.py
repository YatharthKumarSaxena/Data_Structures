from typing import List

class Solution:
    def bellmanFord(self, V: int, edges: List[List[int]], src: int) -> List[int]:

        dist = [float('inf')] * V
        dist[src] = 0

        done = False
        totalEdges = len(edges)

        for _ in range(V - 1):

            updated = False

            for j in range(totalEdges):

                u = edges[j][0]
                v = edges[j][1]
                wt = edges[j][2]

                if dist[u] != float('inf') and dist[u] + wt < dist[v]:
                    dist[v] = dist[u] + wt
                    updated = True

            if not updated:
                done = True
                break

        if not done:
            for j in range(totalEdges):

                u = edges[j][0]
                v = edges[j][1]
                wt = edges[j][2]

                if dist[u] != float('inf') and dist[u] + wt < dist[v]:
                    return [-1]

        for i in range(V):
            if dist[i] == float('inf'):
                dist[i] = 100000000

        return dist