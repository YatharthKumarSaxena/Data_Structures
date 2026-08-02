from typing import List

class Solution:
    def findParent(self, x, parent):
        if parent[x] == x:
            return x
        parent[x] = self.findParent(parent[x], parent)
        return parent[x]

    def Union(self, a, b, parent, rank):
        pa = self.findParent(a, parent)
        pb = self.findParent(b, parent)

        if pa == pb:
            return False

        if rank[pa] < rank[pb]:
            pa, pb = pb, pa

        parent[pb] = pa

        if rank[pa] == rank[pb]:
            rank[pa] += 1

        return True

    def kruskal(self, n, edges, skip, force):

        parent = [i for i in range(n)]
        rank = [0] * n

        weight = 0
        cnt = 0

        if force != -1:
            self.Union(edges[force][0], edges[force][1], parent, rank)
            weight += edges[force][2]
            cnt += 1

        for i in range(len(edges)):

            if i == skip:
                continue

            if self.Union(edges[i][0], edges[i][1], parent, rank):
                weight += edges[i][2]
                cnt += 1

        if cnt != n - 1:
            return float('inf')

        return weight

    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:

        for i in range(len(edges)):
            edges[i].append(i)

        edges.sort(key=lambda x: x[2])

        baseWeight = self.kruskal(n, edges, -1, -1)

        critical = []
        pseudo = []

        for i in range(len(edges)):

            if self.kruskal(n, edges, i, -1) > baseWeight:
                critical.append(edges[i][3])

            elif self.kruskal(n, edges, -1, i) == baseWeight:
                pseudo.append(edges[i][3])

        return [critical, pseudo]