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

    def kruskalsMST(self, V: int, edges: List[List[int]]) -> int:
        edges.sort(key=lambda x: x[2])

        parent = [i for i in range(V)]
        rank = [1] * V

        ans = 0
        allowedEdges = 0
        i = 0

        while allowedEdges < V - 1:
            u, v, wt = edges[i]

            if self.unionGroup(u, v, parent, rank):
                allowedEdges += 1
                ans += wt

            i += 1

        return ans