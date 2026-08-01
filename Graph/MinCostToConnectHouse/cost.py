from typing import List

class Solution:
    def findParent(self, a, parent):
        if parent[a] == a:
            return a
        parent[a] = self.findParent(parent[a], parent)
        return parent[a]

    def unionGroup(self, a, b, parent, rank):
        parA = self.findParent(a, parent)
        parB = self.findParent(b, parent)

        if parA == parB:
            return False

        rankA = rank[parA]
        rankB = rank[parB]

        if rankA >= rankB:
            parent[parB] = parA
            rank[parA] += 1
        else:
            parent[parA] = parB
            rank[parB] += 1

        return True

    def kruskalsMST(self, V, edges):
        edges.sort(key=lambda x: x[2])

        parent = [i for i in range(V)]
        rank = [1] * V

        ans = 0
        allowedEdges = 0
        i = 0

        while allowedEdges < V - 1:
            if self.unionGroup(edges[i][0], edges[i][1], parent, rank):
                allowedEdges += 1
                ans += edges[i][2]
            i += 1

        return ans

    def minCost(self, houses: List[List[int]]) -> int:
        totalNodes = len(houses)
        edges = []

        for i in range(totalNodes - 1):
            for j in range(i + 1, totalNodes):
                wt = abs(houses[i][0] - houses[j][0]) + \
                     abs(houses[i][1] - houses[j][1])

                edges.append([i, j, wt])

        return self.kruskalsMST(totalNodes, edges)