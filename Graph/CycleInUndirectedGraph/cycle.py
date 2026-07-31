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

        if rank[parA] >= rank[parB]:
            parent[parB] = parA
            rank[parA] += 1
        else:
            parent[parA] = parB
            rank[parB] += 1

        return True

    def isCycle(self, V, edges):
        parent = list(range(V))
        rank = [1] * V

        for u, v in edges:
            if not self.unionGroup(u, v, parent, rank):
                return True

        return False