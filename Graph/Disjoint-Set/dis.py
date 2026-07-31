class Solution:
    def findParent(self, a, parent):
        if parent[a] == a:
            return a
        parent[a] = self.findParent(parent[a], parent)
        return parent[a]

    def unionGroup(self, a, b, parent):
        parA = self.findParent(a, parent)
        parB = self.findParent(b, parent)
        parent[parA] = parB

    def DSU(self, n, queries):
        parent = [i for i in range(n + 1)]
        ans = []

        for query in queries:
            if query[0] == 2:
                ans.append(self.findParent(query[1], parent))
            else:
                self.unionGroup(query[1], query[2], parent)

        return ans